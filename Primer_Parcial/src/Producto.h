#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include "Biblioteca.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define SIN_STOCK -3
#define MAX_STOCK 1000

typedef struct
{
	int idProducto;
	short int isEmpty;

	int Fk_vendedor;

	char nombreDelProducto[25];
	float precio;
	int categoria;
	int stock;
} eProducto;

/***
 * \brief Se encarga de cambiar el parametro isEmpty a libre
 * @param arrayProductos Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 */
void eProducto_InicializarProductos(eProducto arrayProductos[], int length);

/***
 * \brief Se encarga de buscar en el array el index donde isEmpty se encuentra con valor 'LIBRE'
 * @param arrayProductos arrayProductos Array con los contenidos a modificar y trabajar
 * @param length  Tamanio del Array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eProducto_ObtenerIndexLibre(eProducto arrayProductos[], int length);

/***
 *\brief Busca un index, dentro del array, asosiado al ID
 * @param arrayProductos Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param ID Valor que identifica los elementos del array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eProducto_BuscarPorId(eProducto arrayProductos[], int length, int ID);

/***
 * \brief Imprime todos los campos de una variable
 * @param Producto Es una variable terminada
 */
void eProducto_ImprimirProducto(eProducto Producto);

/***
 * \brief Imprime todos los campos de los distintos elementos de un array
 * 			se puede elegir un estado en concreto
 * @param arrayProductos  Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param estado valor que determina si el elemento se encuentra 'libre', 'ocupado', 'baja'
 * @return Retorna el total dependiendo del estado al mostar los datos o un -1 si no hay nada que mostrar
 */
int eProducto_ImprimirProductos(eProducto arrayProductos[], int length);

int eProducto_ImprimirProductosPorUser(eProducto arrayProductos[], int length, int ID);

/***
 * \brief Se encarga de pedir los datos que se quieran ingrear en un determinado elemento
 * @return Retorna los datos de los campos de un elemento
 */
int eProducto_CargarDatos(eProducto *Producto);


int eProducto_Alta(eProducto arrayProductos[], int length, int ID);
/***
 * \brief Hace una baja logica de un elemento que decida el Producto y cambiando su estado a 'BAJA'
 * @param arrayProductos Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eProducto_RemoverProducto(eProducto arrayProductos[], int length);

/***
 * \brief Selecciona un elemento del Array que decida el Producto y modifica los campos seleccionados
 * @param arrayProductoscon los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eProducto_Modificacion(eProducto arrayProductos[], int length);

/**
 * \brief Se encarga de Calcular el total promedio de gastos de los pasajeros e imprime los superiores al promedio
 * @param arrayProductos Cadena que guarda a los pasajeros
 * @param ProductoLen	Tamanio de la Cadena
 * @return Retorna un -1 si hubo un error, o un 0 si salio bien
 */

/* Ordenamiento*/

/***
 * \brief Se encarga de ordenar los elementos de un array dependiendo del criterio elegido
 * @param arrayProductoss arrayProductoscon los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eProducto_SortProducto(eProducto arrayProductos[], int length, int criterio);

void eProducto_Hardcodeo(eProducto* arrayProductos, int length);

#endif /* PRODUCTO_H_ */
