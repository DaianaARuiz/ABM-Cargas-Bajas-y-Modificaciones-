#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas-mascotas.h"
#define TAM_RAZA 10
#define TAM_MASC 20
#define TRUE 1
#define FALSE 0

//////////////////////////////HARCODEO////////////////////////////////////////HARCODEO/////////////////////////////////////
void HarcodearMascotas(eMascotas listaMasc[])
{
    int idMascota[]={100,200,300,400,500,600,700};
    char nombre[][20]={"Michi","Yoyo","Dobby","Mimi","Tomy","Roman","Genaro"};
    int edad[]={3,2,4,7,2,8,9};
    char sexo[]={'f','m','f','m','m','m','m'};
    char tipo[][10]={"Gato","Perro","Gato","Perro","Gato","Perro","Perro"};
    int idRaza[]={150,135,180,318,150,130,140};
    int peso[]={10,20,5,16,7,8,13};


    for(int i=0;i<7;i++)
    {
        listaMasc[i].idMascota=idMascota[i];
        strcpy(listaMasc[i].nombreMascota,nombre[i]);
        listaMasc[i].edad=edad[i];
        strcpy(listaMasc[i].tipoMascota,tipo[i]);
        listaMasc[i].sexoMascota=sexo[i];
        listaMasc[i].peso=peso[i];
        listaMasc[i].idRaza=idRaza[i];

        listaMasc[i].isEmpty=FALSE;
    }
}

//////////////////////ALTA MASCOTA////////////////////////////////////////ALTA MASCOTA////////////////////////////////////////////
int InicializarArrayMascotas(eMascotas listaMasc[],int tamanioArray)
{
    int retorno;
	retorno=-1;
    for(int i=0;i <tamanioArray; i++)
    {
        listaMasc[i].isEmpty =TRUE;
        retorno=0;
    }
    return retorno;
}

 int BuscarLibreMascota(eMascotas listaMasc[], int tamanioArray)
 {
     int index=-1;
     for(int i=0;i<tamanioArray;i++)
     {
         if(listaMasc[i].isEmpty==TRUE)
         {
             index=i;
             break;
         }
     }
     return index;
 }

 eMascotas AltaMascotas(eMascotas listaMasc[],int tamanioArray, int indiceLibre,int tamRaza, eRazas listaRazas[])
 {
    eMascotas unaMascota;

    PedirString("\nIngrese nombre mascota: ","Error. Reingrese nombre: ",20, unaMascota.nombreMascota);
    PedirString("Ingrese el tipo de mascota: ","Error. Reingrese tipo: ",10, unaMascota.tipoMascota);
    unaMascota.edad= PedirEntero("Ingrese edad de la mascota: ","Error, reingrese edad valida:");
    unaMascota.sexoMascota=getChar("Ingrese sexo mascota(f o m): ");
    unaMascota.peso= PedirFlotante("Ingrese el peso de la mascota: ","Error, reingrese peso valido:");

    ListarRazas(listaRazas,tamRaza);
    unaMascota.idRaza=PedirEntero("\nIngrese el id de la raza de la mascota: ","Error, reingrese id valido:");

    unaMascota.isEmpty=FALSE;
    unaMascota.idMascota=listaMasc[indiceLibre-1].idMascota+100;
    listaMasc[indiceLibre]=unaMascota;

    return unaMascota;
 }

 //////////////////////////MODIFICAR MASCOTA////////////////////////////////////////////MODIFICAR MASCOTA///////////////////////////////////////////////
int ModificarUnaMascota( eMascotas listaMasc[],int idAModificar,int opcion, int tamanioArray,eRazas listaRazas[],int tamRaza)
{
    int indiceIDbuscado=BuscarPorID(idAModificar,tamanioArray,listaMasc);
    char nombreModificado[10];
    char tipoModificado[10];
    int retorno=-1;

    switch(opcion)
    {
        case 1:
            PedirString("Ingrese el nuevo nombre:","Error. Reingrese nombre: ",51,nombreModificado);
            strcpy(listaMasc[indiceIDbuscado].nombreMascota,nombreModificado);
            retorno=0;
            break;
        case 2:
             listaMasc[indiceIDbuscado].edad=PedirEntero("Ingrese nueva edad: ","Error, reingrese edad valida: ");
             retorno=0;
             break;
        case 3:
            PedirString("Ingrese el nuevo tipo:","Error. Reingrese tipo: ",51,tipoModificado);
            strcpy(listaMasc[indiceIDbuscado].tipoMascota,tipoModificado);
            retorno=0;
            break;
        case 4:
           listaMasc[indiceIDbuscado].sexoMascota=getChar("Ingrese nuevo sexo: ");
            retorno=0;
           break;
        case 5:
            listaMasc[indiceIDbuscado].peso=PedirFlotante("Ingrese nuevo peso: ","Error, reingrese peso valido: ");
            retorno=0;
            break;
        case 6:
            ListarRazas(listaRazas,tamRaza);
            listaMasc[indiceIDbuscado].idRaza=PedirEntero("\nIngrese nuevo idRaza: ","Error, reingrese id raza valido: ");
            retorno=0;
            break;
        default:
                printf("\nOpcion no valida. Intente nuevamente\n");
                break;
    }
    return retorno;
}

/////////////////////BAJA MASCOTA////////////////////////////////////////////////BAJA MASCOTA/////////////////////////////////////////////
int eliminarUnaMascota(eMascotas listaMasc[],int tamanioArray, int idEliminar)
{
    int retorno=-1;
    int indiceIDbuscado=BuscarPorID(idEliminar,tamanioArray,listaMasc);
    if(indiceIDbuscado!=-1)
    {
        retorno=0;
        listaMasc[indiceIDbuscado].isEmpty=TRUE;
    }
    return retorno;
}

int BuscarPorID(int idIngresado, int tam, eMascotas listaMasc[])
{
    int indiceIDbuscado=-1;
    for(int i=0;i<tam;i++)
    {
       if(listaMasc[i].idMascota==idIngresado)
       {
            indiceIDbuscado=i;
            break;
       }
    }
    return indiceIDbuscado;
}

///////////////////////INFORMAR//////////////////////////////////////INFORMAR/////////////////////////////////////////////
void ListarMascotas(eMascotas listaMasc[], int tamanioArray)
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de mascotas: \n\n");
    printf("ID \tNOMBRE\tTIPO\t EDAD \tSEXO\t PESO\n");
    for(int i=0;i<tamanioArray;i++)
    {
        imprimirUnaMascota(listaMasc[i]);
    }
    printf("\n*********************************************************************************");
}

void imprimirUnaMascota(eMascotas unaMascota)
{
     printf("%4d %8s %8s %4d %4c %14f\n",   unaMascota.idMascota,
                                            unaMascota.nombreMascota,
                                            unaMascota.tipoMascota,
                                            unaMascota.edad,
                                            unaMascota.sexoMascota,
                                            unaMascota.peso);
}


