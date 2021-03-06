#include "mascotas.h"
#include "razas.h"
#include "pais.h"


//ALTA MASCOTAS MOSTRANDO ID DE RAZA
eMascotas AltaMascotas(eMascotas [],int , int ,int , eRazas []);

///////////////MODIFICAR MASCOTA//////////////////
 int ModificarUnaMascota( eMascotas [],int ,int , int ,eRazas [],int);

void ListarMascotasOrdenadasPorCodigoTelefonico(eMascotas [], int , eRazas [], int ,ePaisOrigen [],int );
void ImprimirListadoMascotasPais(eMascotas ,eRazas ,ePaisOrigen);
ePaisOrigen EncontrarPaisDeUnaRaza(eRazas ,ePaisOrigen [],int);
void OrdenarMascotasPorCodigoTelefonico(eMascotas [],ePaisOrigen ,int );

//////////INGRESO DE DATOS////////////////////
int PedirEntero(char [],char []);
int ValidarNumero(char []);
void PedirString(char [],char [],int , char []);
int ValidarLetras(char []);
char getChar(char mensaje[]);
float PedirFlotante(char [],char []);
int ValidarFlotante(char []);
void ObtenerTamanioRazaValido(char[],char[],char[]);

//listado de mascotas con sus razas y pa�ses de origen:
void ListarMascotasConRaza(eMascotas [], int , eRazas [], int);
eRazas EncontrarRazaDeUnaMascota(eRazas [],int , int );
void ImprimirMascotaConRaza(eMascotas,eRazas);

//listado de RAZAS con las mascotas que pertenecen a esa raza:
void ListarPorCadaRazaLasMascotas(eMascotas [], int , eRazas [], int );
void EncontrarMascotasDeUnaRaza(eMascotas [],int,int);

//listado de mascotas ordenadas por peso:
int OrdenarMascotasPorPeso(eMascotas [], int);

//mostrar el pa�s de origen que tenga m�s mascotas:
void MostrarPaisConMasMascotas(eMascotas [], int  , eRazas [], int);
void ContarMascotasRazas(eMascotas [],int ,int ,int [],int);
