/*
 * Biblioteca.c
 *
 *  Created on: 3 may 2022
 *      Author: Mi PC
 */

#include "Biblioteca.h"

/***
 * \brief Pide una Cadena de Caracteres
 * @param cadena Puntero al espacio de memoria donde se guarda la Cadena
 * @param longitud Tamanio de la cadena
 * @return Retorna 0 (EXITO) si se obtiene el numero entero y -1 si no
 */
int getString(char cadena[], int longitud);

/**
 * \brief Obtiene un numero entero
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene el numero entero y -1 si no
 */
static int getInt(int *pResultado);

/***
 * \brief obtiene y verifica si es un numero flotante
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return Retorna 0 (EXITO) si se obtiene el numero flotante y -1 si no
 */

static int getFloat(float *pResultado);

/***
 * \brief Verifica la cadena ingresada si es numerica
 * @param cadena Cadena a ser analizada
 * @param tam Tamanio de la cadena (usar 'sizeoff')
 * @return Retorna un '-1' en caso de ERROR, 1 si es verdadero(Cadena numerica), 0 si es falso (Encontro algo no numerico)
 */
static int esNumerica(char cadena[], int tam);

/***
 * \brief Verifica la cadena ingresada si es un Flotante
 * @param cadena Cadena a ser analizada
 * @param tam Tamanio de la cadena (usar 'sizeoff')
 * @return Retorna un '-1' en caso de ERROR, 1 si es verdadero(Cadena numerica), 0 si es falso (Encontro algo no valido para float)
 */
static int esFlotante(char cadena[], int tam);

/***
 * \brief Verifica que la cadena contenga caracteres (por ASCII)
 * @param cadena Puntero de la cadena a verificar
 * @param longitud largo de la cadena (usar 'sizeoff')
 * @return  Retorna un '-1' en caso de ERROR, 1 si es verdadero(Cadena numerica), 0 si es falso (Encontro algo no valido para float)
 */
static int esNombre(char *cadena, int longitud);

static int esAlfaNumerica(char *cadena, int longitud);


static int getAlfaNumerica(char *pResultado, int longitud);


static int esConCaracteresEspeciales(char *cadena, int longitud);


static int getCaracteresEspecificos(char *pResultado, int longitud);

/***
 * \brief Pide una cadena de caracteres, y la verifica
 * @param pResultado Puntero de la memoria donde se aloja la memoria
 * @param longitud largo de la cadena (usar 'sizeoff')
 * @return Retorna un '-1' en caso de ERROR, 1 si es verdadero(Cadena numerica), 0 si es falso (Encontro algo no valido para float)
 */

static int getNombre(char *pResultado, int longitud);

int getString(char cadena[], int longitud)
{
	int retorno = -1;
	char bufferString[1024];

	if (cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

static int getInt(int *pResultado)
{
	int retorno = -1;
	char bufferSting[50];

	if (pResultado != NULL)
	{
		if (getString(bufferSting, sizeof(bufferSting)) == 0 && esNumerica(bufferSting, sizeof(bufferSting)))
		{
			*pResultado = atoi(bufferSting);
			retorno = 0;
		}
	}
	return retorno;
}

static int getFloat(float *pResultado)
{
	int retorno = -1;
	char bufferSting[50];

	if (pResultado != NULL)
	{
		if (getString(bufferSting, sizeof(bufferSting)) == 0 && esFlotante(bufferSting, sizeof(bufferSting)))
		{
			*pResultado = atof(bufferSting);
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char cadena[], int tam)
{
	int retorno = -1;
	int i;

	if (cadena != NULL && tam > 0)
	{
		retorno = 1;
		for (i = 0; i < tam && cadena[i] != '\0'; i++)
		{
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

static int esFlotante(char cadena[], int tam)
{
	int retorno = -1;
	int i;
	int contadorPuntos = 0;

	if (cadena != NULL && tam > 0)
	{
		retorno = 1;
		for (i = 0; i < tam && cadena[i] != '\0'; i++)
		{
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9')
			{
				if (cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}
static int esNombre(char *cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0)
	{
		for (i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if ((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
static int getNombre(char *pResultado, int longitud)
{
	int retorno = -1;
	char bufferSting[1024];

	if (pResultado != NULL)
	{
		if (getString(bufferSting, sizeof(bufferSting)) == 0 && esNombre(bufferSting, sizeof(bufferSting)) && strnlen(bufferSting, sizeof(bufferSting)) < longitud)
		{
			strncpy(pResultado, bufferSting, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

static int esAlfaNumerica(char *cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0)
	{
		for (i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if (cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int esConCaracteresEspeciales(char *cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0)
	{
		for (i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] =='@' || cadena[i] == '.')
			{
				continue;
			}
			if (cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int validar_Salida_SN(char *mensaje, char *mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[2];

	if (mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		printf("%s", mensaje);
		do
		{
			if (getNombre(bufferString, sizeof(bufferString)) == 0)
			{
				for (int i = 0; i < sizeof(bufferString); i++)
				{
					bufferString[i] = toupper(bufferString[i]);
				}
				if (strcmp(bufferString, "S") == 0)
				{
					retorno = 1;
					break;
				}
				if (strcmp(bufferString, "N") == 0)
				{
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos != 0);
	}
	return retorno;
}

static int getAlfaNumerica(char *pResultado, int longitud)
{
	int retorno = -1;
	char bufferSting[1024];

	if (pResultado != NULL)
	{
		if (getString(bufferSting, sizeof(bufferSting)) == 0 && esAlfaNumerica(bufferSting, sizeof(bufferSting)) && strnlen(bufferSting, sizeof(bufferSting)) < longitud)
		{
			strncpy(pResultado, bufferSting, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

static int getCaracteresEspecificos(char *pResultado, int longitud)
{
	int retorno = -1;
	char bufferSting[1024];

	if (pResultado != NULL)
	{
		if (getString(bufferSting, sizeof(bufferSting)) == 0 && esConCaracteresEspeciales(bufferSting, sizeof(bufferSting)) && strnlen(bufferSting, sizeof(bufferSting)) < longitud)
		{
			strncpy(pResultado, bufferSting, longitud);
			retorno = 0;
		}
	}
	return retorno;
}


int utn_GetAlfaNumerico(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado)
{
	char bufferString[1024];
	int retorno = -1;
	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if (getAlfaNumerica(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_GetPassword(char *mensaje, char *mensajeError, int reintentos,int minimo ,int longitud, char *pResultado)
{
	char bufferString[1024];
	int retorno = -1;
	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if (getAlfaNumerica(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud && strnlen(bufferString, sizeof(bufferString)) > minimo)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_GetEmail(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado)
{
	char bufferString[1024];
	int retorno = -1;
	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if (getCaracteresEspecificos(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_GetNumero(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
	int retorno = -1;
	int auxiliarInt;

	if (mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		do
		{

			printf("%s", mensaje);
			if (getInt(&auxiliarInt) == 0 && auxiliarInt < maximo && auxiliarInt > minimo)
			{
				*pNumeroIngresado = auxiliarInt;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;

		} while (reintentos > 0);
	}
	return retorno;
}

int utn_GetNumeroFlotante(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado)
{
	int retorno = -1;
	float auxiliarFloat;

	if (mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		do
		{

			printf("%s", mensaje);
			if (getFloat(&auxiliarFloat) == 0 && auxiliarFloat < maximo && auxiliarFloat > minimo)
			{
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;

		} while (reintentos > 0);
	}
	return retorno;
}

int utn_getString(char *mensaje, char *mensajeError, int reintentos, int longitud, char *pResultado)
{
	char bufferString[1024];
	int retorno = -1;
	while (reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int GetFloatPositivo(char mensaje[], float *pNumeroIngresado, char mensajeError[], int reintentos)
{
	int retorno = -1;
	float auxiliarInt;
	int retornoScanf;

	if (mensaje != NULL && mensajeError != NULL && reintentos > 0 && pNumeroIngresado != NULL)
	{
		printf("%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarInt);
		do
		{
			if (retornoScanf != 1 || auxiliarInt < 0)
			{
				printf("%s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarInt);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = auxiliarInt;
				retorno = 0;
			}
		} while (reintentos > 0);
	}

	return retorno;
}

int ImprimirDiferencia(float primerNumero, float segundoNumero, char mensaje[])
{
	float diferencia;
	int retorno;
	retorno = -1;

	if (mensaje != NULL)
	{
		if (primerNumero > segundoNumero)
		{
			diferencia = Restar(primerNumero, segundoNumero);
			retorno = 0;
		}
		else
		{
			diferencia = Restar(segundoNumero, primerNumero);
			retorno = 0;
		}
	}
	printf("%s%.2f\n\n", mensaje, diferencia);
	return retorno;
}

int imprimirArrayInt(int *pArray, int limite)
{
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0)
	{
		for (i = 0; i < limite; i++)
		{
			printf("\nINDICE %d - VALOR : %d", i, pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int ordenarArrayInt(int *pArray, int limite)
{
	int iteraciones = 0;
	int i;
	int flagSwap;
	int buffer;
	int retorno = -1;
	int nuevoLimite;

	if (pArray != NULL && limite > 0)
	{
		nuevoLimite = limite - 1;
		do
		{
			flagSwap = 0;
			for (i = 0; i < nuevoLimite; i++)
			{
				if (pArray[i] < pArray[i + 1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = buffer;
				}
				iteraciones++;
			}
			nuevoLimite--;
		} while (flagSwap);
		retorno = iteraciones;
	}

	return retorno;
}

//CALCULOS

float Sumar(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 + numero2;
	return resultado;
}
float Restar(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 - numero2;
	return resultado;
}
float Multiplicar(float numero1, float numero2)
{
	float resultado;
	resultado = numero1 * numero2;
	return resultado;
}
float Dividir(float divisor, float dividendo)
{
	float cociente;
	if (dividendo != 0)
	{
		cociente = divisor / dividendo;
	}
	else
	{
		cociente = 0;
	}
	return cociente;
}

int CalcularPorReglaSimple(float primerNumero, float segundoNumero, float tercerNumero, float *resultado)
{
	int retorno;
	float resultadoMultiplicacion;
	float resultadoAuxiliar;

	retorno = -1;

	if (primerNumero != 0 && resultado != NULL)
	{
		resultadoMultiplicacion = Multiplicar(tercerNumero, segundoNumero);
		resultadoAuxiliar = Dividir(resultadoMultiplicacion, primerNumero);
		*resultado = resultadoAuxiliar;
		retorno = 0;
	}

	return retorno;
}


//FUNCIONES PARA EL TIEMPO

long int timeCurrent(void)
{
	return time(NULL);
}

long int time_Add(double seccondsAdd)
{
	return seccondsAdd + timeCurrent();
}


// PARA EL PROGRAMA

void mostrarTituloMenu(int tipoDeMenu)
{
	//TODO Hacerlo con una variable recibida, no es tan complicado.
	char titulo[25] =
	{ "1er EXAMEN LAB I - 1H" };
	char titulo2[10] =
	{ "USUARIO" };
	char titulo3[10] =
	{ "ADMIN" };

	switch (tipoDeMenu)
	{
	case 1:
		puts("\t***************************");
		printf("\t** %15s **\n", titulo);
		puts("\t***************************");
		break;
	case 2:
		puts("\t***************************");
		printf("\t** %15s **\n", titulo);
		printf("\t**%14s         **\n", titulo2);
		puts("\t***************************");
		break;
	case 3:
		puts("\t***************************");
		printf("\t** %15s **\n", titulo);
		printf("\t**%14s         **\n", titulo3);
		puts("\t***************************");
		break;

	}
}

int calcularDistancia(int distanciaRecorrido)
{
	int retorno = -1;

	if (distanciaRecorrido > 0 && distanciaRecorrido < 10001)
	{
		if (distanciaRecorrido > 8000)
		{
			retorno = 150;
		}
		else
		{
			if (distanciaRecorrido > 5000)
			{
				retorno = 80;
			}
			else
			{
				if (distanciaRecorrido > 3000)
				{
					retorno = 50;
				}
				else
				{
					if (distanciaRecorrido > 1000)
					{
						retorno = 30;
					}
					else
					{
						retorno = 20;
					}
				}
			}
		}

	}
	return retorno;
}
