/*
 * Biblioteca.h
 *
 *  Created on: 3 may 2022
 *      Author: Mi PC
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**
 * \brief Pide un numero entero y realiza las comprovaciones
 * @param mensaje Guarda el mensaje que queres mostrar al usuario
 * @param reintentos La cantidad maxima de veces que se puede repetir un error
 * @param minimo El numero minimo que se puede ingresar
 * @param maximo El numero maximo que se puede ingresar
 * @param mensajeError	mensaje que se muestra en caso de error
 * @param pNumeroIngresado puntero donde enviara la variable pedida
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int utn_GetNumero(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);

/**
 * \brief Variable de GetFloat, solo pide y obtiene numeros positivos
 * @param mensaje Mensaje dirigido al ususario
 * @param pNumeroIngresado Puntero donde se guarda el numero ingresado
 * @param mensajeError	mensaje que se muestra en caso de error
 * @param reintentos cantidad de reintentos en caso de error
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int GetFloatPositivo(char mensaje[], float *pNumeroIngresado, char mensajeError[], int reintentos);

/**
 * \brief Pide y obtiene un numero Float
 * @param mensaje Mensaje dirigido al Usuario
 * @param reintentos eintentos La cantidad maxima de veces que se puede repetir un error
 * @param minimo minimo El numero minimo que se puede ingresar
 * @param maximo El numero maximo que se puede ingresar
 * @param mensajeError Mensaje que se muestra en caso de error
 * @param pNumeroIngresado Puntero donde se guarda el numero ingresado
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int utn_GetNumeroFlotante(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);

/***
 *
 * @param mensaje
 * @parammensaje Mensaje dirigido al Usuario
 * @param reintentos eintentos La cantidad maxima de veces que se puede repetir un error
 * @param longitud Tamanio maximo de la cadena
 * @param pResultado Puntero a la memoria donde se guarda la cadena
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int utn_getString(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado);

/**
 * \brief Recibe y guarda en en char String letras, numeros
 * @param cadena array String
 * @param tam Tamanio del String
 * @param mensaje Mensaje dirijido a usuario
 * @return Devuelve un -1 si hubo un erorr, 0 si se logro la funcion
 */

int utn_GetAlfaNumerico(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado);

/***
 * \brief Sirve para validar dos opciones, Con una S o un N
 * @param mensaje Mensaje que quieres mostrar
 * @param mensajeError Mensaje por un ingreso invalido
 * @param reintentos cantidad de reintentos
 * @return Devuelve un 1 con un con S, un 0 con N
 */
int validar_Salida_SN(char *mensaje, char *mensajeError, int reintentos);

int utn_GetEmail(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado);

int utn_GetPassword(char *mensaje, char *mensajeError, int reintentos, int minimo, int longitud, char *pResultado);

//PARA LA APP
/**
 * \brief Se encarga de mostrar el encabezado del menu
 * @param tipoDeMenu Selecciona 1, Para Menu principal, 2 menu User, 3 Menu Admin
 */
void mostrarTituloMenu(int tipoDeMenu);

// FUNCIONES DE LOGICA Y OPERACIONES

/**
 * \brief Funcion que realiza una suma
 * @param numero1 Primer numero Ingresado, se espera un float
 * @param numero2 Segundo numero Ingreado, se espera un float
 * @return El resultado de la cuenta
 */
float Sumar(float numero1, float numero2);

/**
 * \brief Funcion que realiza una resta
 * @param Numero1 Primer numero Ingresado, se espera un float
 * @param Numero2 Segundo numero Ingresado, se espera un float
 * @return El resultado de la cuenta
 */
float Restar(float numero1, float numero2);

/**
 * \brief Funcion que realiza una multiplicacion
 * @param numero1 Primer numero Ingresado, se espera un float
 * @param numero2 Segundo numero Ingresado, se espera un float
 * @return El resultado de la cuenta
 */
float Multiplicar(float numero1, float numero2);

/**
 * \brief Funcion que realiza una division, no calcula una division por 0
 * @param divisor El numero que se desea dividir
 * @param dividendo el numero por el cual se va a dividir
 * @return El resultado de la division
 */
float Dividir(float divisor, float dividendo);

/**
 * \brief Funcion que aplica la regla de 3 simple
 * @param primerNumero Es el numero A en la regla
 * @param segundoNumero Es el numero B en la regla
 * @param tercerNumero Es el numero C en la regla
 * @param resultado variable donde se guarda el resultado de los calculos
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int CalcularPorReglaSimple(float primerNumero, float segundoNumero, float tercerNumero, float *resultado);

/**
 * \brief Funcion que Imprime una diferencia, muestra el resultado en positivo
 * @param primerNumero Primer numero Ingresado, se espera un float
 * @param segundoNumero Segundo numero Ingresado, se espera un float
 * @param mensaje Mensaje que acompaña al resultado de la diferencia
 * @return Un -1 si hubo un error, 0 si se logro la funcion
 */
int ImprimirDiferencia(float primerNumero, float segundoNumero, char mensaje[]);

/***
 * \brief Imprime la informacion de un array INT
 * @param pArray Es el puntero Array a ser ordenado
 * @param limite Es la longitud del array
 * @return Retorna 0 o -1 si hubo un ERROR
 */
int imprimirArrayInt(int *pArray, int limite);

/***
 * \brief Ordenar un Array de enteros
 * @param pArray Es el puntero Array a ser ordenado
 * @param limite Es la longitud del array
 * @return Retorna la Cantidad de iteraciones necesarias para ordenar, -1 si hubo un ERROR
 */

int ordenarArrayInt(int *pArray, int limite);

int calcularDistancia(int distanciaRecorrido);


/**
 * \brief Calcula el tiempo ACTUAL
 * @return
 */
long int timeCurrent(void);

/***
 * \brief Agrega  x segundos a el tiempo Actual
 * @param seccondsAdd Cantidad de segundos a agregar
 * @return retorna el TIEMPO en forma int
 */
long int time_Add(double seccondsAdd);

#endif /* BIBLIOTECA_H_ */
