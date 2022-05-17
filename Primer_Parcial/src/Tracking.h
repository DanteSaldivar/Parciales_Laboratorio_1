#ifndef TRACKING_H_
#define TRACKING_H_
#include "Biblioteca.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int idTracking;
	int idProducto;
	short int isEmpty;

	int Fk_vendedor;
	int Fk_comprador;

	int cantidad;
	int distanciaKM;
	long int horaLlegada;
} eTracking;

/***
 * \brief Se encarga de cambiar el parametro isEmpty a libre
 * @param arrayTrackings Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 */
void eTracking_InicializarTrackings(eTracking arrayTrackings[], int length);

/***
 * \brief Se encarga de buscar en el array el index donde isEmpty se encuentra con valor 'LIBRE'
 * @param arrayTrackings arrayTrackings Array con los contenidos a modificar y trabajar
 * @param length  Tamanio del Array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eTracking_ObtenerIndexLibre(eTracking arrayTrackings[], int length);

/***
 *\brief Busca un index, dentro del array, asosiado al ID
 * @param arrayTrackings Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param ID Valor que identifica los elementos del array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eTracking_BuscarPorId(eTracking arrayTrackings[], int length, int ID);

/***
 * \brief Imprime todos los campos de una variable
 * @param Tracking Es una variable terminada
 */
void eTracking_ImprimirTracking(eTracking Tracking);

/***
 * \brief Imprime todos los campos de los distintos elementos de un array
 * 			se puede elegir un estado en concreto
 * @param arrayTrackings  Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param estado valor que determina si el elemento se encuentra 'libre', 'ocupado', 'baja'
 * @return Retorna el total dependiendo del estado al mostar los datos o un -1 si no hay nada que mostrar
 */
int eTracking_ImprimirTrackings(eTracking arrayTrackings[], int length);


/***
 * \brief Sirve para CANCELAR un Tracking
 * @param arrayTrackings Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eTracking_CancelarTracking(eTracking arrayTrackings[], int length, int ID);


/* Ordenamiento*/



#endif /* TRACKING_H_ */
