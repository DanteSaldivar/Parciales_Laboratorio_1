
#ifndef USUARIOS_H_
#define USUARIOS_H_
#include "Biblioteca.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define USUARIO -11
#define ADMIN -10

typedef struct
{
	int idUsuario;
	short int isEmpty;

	short int tipo;

	char correo[25];
	char password[10];
	char direccion[50];
	int codPostal;
} eUsuario;

/***
 * \brief Se encarga de cambiar el parametro isEmpty a libre
 * @param arrayUsuarios Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 */
void eUsuario_inicializarUsuarios(eUsuario arrayUsuarios[], int length);
/***
 * \brief Valida el inicio de Sesion
 * @param arrayUsuarios Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param ID id del Usuario que se loguea
 * @param tipoIngreso puntero a short int, para tipo de usuario
 * @return
 */
int eUsuario_InicioDeSesion(eUsuario arrayUsuarios[],int length,int* ID, short int* tipoIngreso);

/***
 * \brief Se encarga de buscar en el array el index donde isEmpty se encuentra con valor 'LIBRE'
 * @param arrayUsuarios arrayUsuarios Array con los contenidos a modificar y trabajar
 * @param length  Tamanio del Array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eUsuario_ObtenerIndexLibre(eUsuario arrayUsuarios[], int length);

/***
 *\brief Busca un index, dentro del array, asosiado al ID
 * @param arrayUsuarios Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @param ID Valor que identifica los elementos del array
 * @return Retorna un index si salio bien o un -1 si hubo un error
 */
int eUsuario_BuscarUsuarioPorId(eUsuario arrayUsuarios[], int length, int ID);

/***
 * \brief Imprime todos los campos de una variable
 * @param Usuario Es una variable terminada
 */
void eUsuario_ImprimirUsuario(eUsuario Usuario);
/***
 * \brief Imprime todos los campos de los distintos elementos de un array
 * @param arrayUsuarios  Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return Retorna el total dependiendo del estado al mostar los datos o un -1 si no hay nada que mostrar
 */
int eUsuario_ImprimirUsuarios(eUsuario arrayUsuarios[], int length);

/***
 * \brief Carga los campos de la Estructura, y los manda por puntero
 * @param Usuario Es la variable que va a ser modificado
 * @return retorna un -1 si hubo un error, un 0 si salio bien
 */
int eUsuario_CargarDatos(eUsuario* Usuario);

int eUsuario_Alta(eUsuario arrayUsuarios[], int length);

/***
 * \brief Hace una baja logica de un elemento que decida el usuario y cambiando su estado a 'BAJA'
 * @param arrayUsuarios Array con los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eUsuario_DarDeBaja(eUsuario arrayUsuarios[], int length);

/***
 * \brief Selecciona un elemento del Array que decida el usuario y modifica los campos seleccionados
 * @param arrayUsuarioscon los contenidos a modificar y trabajar
 * @param length Tamanio del Array
 * @return retorna un 0 si se logro o un -1 si hubo un error
 */
int eUsuario_Modificacion(eUsuario arrayUsuarios[], int length);



void eUsuario_Hardcodeo(eUsuario* arrayUsuarios, int length);

#endif /* USUARIOS_H_ */
