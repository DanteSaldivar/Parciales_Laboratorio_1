/*
 * Arcade.c
 *
 */

#include "Arcade.h"

Arcade* Arcade_new(void)
{
	Arcade *auxiliarP = NULL;

	auxiliarP = (Arcade*) malloc(sizeof(Arcade));
	return auxiliarP;
}

void* Arcade_getById(LinkedList* pArrayListArcade, int id)
{
	Arcade* pAux = NULL;
	int lengthArray;
	int auxId;

	lengthArray = ll_len(pArrayListArcade);

	if(pArrayListArcade != NULL && id > 0)
	{
		for(int i = 0; i < lengthArray; i++)
		{
			pAux = (Arcade*)ll_get(pArrayListArcade, i);
			if(pAux != NULL)
			{

				Arcade_getId(pAux, &auxId);
				if(auxId == id)
				{
					break;
				}
				else
				{
					pAux = NULL;
				}
			}
		}
	}
	return pAux;
}

Arcade* Arcade_newParametros(char* idStr, char* nacionalidadStr, char* tipoSonido, char* cantidadJugadores,char* capacidadMaximaFichas,char* idSalon, char* idJuego)
{
	Arcade* auxiliar = Arcade_new();
	int banderaCompletado = 0;
	int auxTipoSonido;



	if (auxiliar != NULL)
	{
		if (esNumerica(idStr, sizeof(idStr)) && esNombre(nacionalidadStr, sizeof(nacionalidadStr)) && esNombre(tipoSonido, sizeof(tipoSonido))
				&& esNumerica(cantidadJugadores, sizeof(cantidadJugadores)) && esNumerica(capacidadMaximaFichas, sizeof(capacidadMaximaFichas))
				&& esNumerica(idSalon, sizeof(idSalon)) && esNumerica(idJuego, sizeof(idJuego)))
			{
			if(!Arcade_setId(auxiliar, atoi(idStr)) && !Arcade_setNacionalidad(auxiliar, nacionalidadStr)
					&& !Arcade_setCantidadJugadores(auxiliar, atoi(cantidadJugadores)) && !Arcade_setCapacidadMaximaFichas(auxiliar, atoi(capacidadMaximaFichas))
					&& !Arcade_setIdJuego(auxiliar, atoi(idJuego)) && !Arcade_setIdSalon(auxiliar, atoi(idSalon)))
			{
				auxTipoSonido = convertirTipoSonido(tipoSonido);

				if(!Arcade_setTipoSonido(auxiliar, auxTipoSonido))
				{
					banderaCompletado = 1;
				}
			}
		}
	}
	if (banderaCompletado == 0)
	{
		Arcade_delete(auxiliar);
		auxiliar = NULL;
	}

	return auxiliar;
}


void Arcade_delete(Arcade *this)
{
	if (this != NULL)
	{
		free(this);
	}
}


int Arcade_setNacionalidad(Arcade *this, char *nacionalidad)
{
	int retorno = -1;
	if (this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}
	return retorno;
}
int Arcade_getNacionalidad(Arcade *this, char *nacionalidad)
{
	int retorno = -1;
	if (this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}


int Arcade_setId(Arcade *this, int id)
{
	int retorno = -1;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Arcade_getId(Arcade *this, int *id)
{
	int retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}


int Arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int retorno = -1;

	if (this != NULL && tipoSonido > 0)
	{
		this->tipoSonido = tipoSonido;
		retorno = 0;
	}
	return retorno;
}
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int retorno = -1;

	if (this != NULL && tipoSonido != NULL)
	{
		*tipoSonido = this->tipoSonido;
		retorno = 0;
	}
	return retorno;
}


int Arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores)
{
	int retorno = -1;

	if (this != NULL && cantidadJugadores > 0)
	{
		this->cantidadJugadores = cantidadJugadores;
		retorno = 0;
	}
	return retorno;
}
int Arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores)
{
	int retorno = -1;

	if (this != NULL && cantidadJugadores != NULL)
	{
		*cantidadJugadores = this->cantidadJugadores;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setCapacidadMaximaFichas(Arcade* this,int cantidadMaximaFichas)
{
	int retorno = -1;

	if (this != NULL && cantidadMaximaFichas > 0)
	{
		this->capacidadMaximaFichas = cantidadMaximaFichas;
		retorno = 0;
	}
	return retorno;
}
int Arcade_getCapacidadMaximaFichas(Arcade* this,int* cantidadMaximaFichas)
{
	int retorno = -1;

	if (this != NULL && cantidadMaximaFichas != NULL)
	{
		*cantidadMaximaFichas = this->capacidadMaximaFichas;
		retorno = 0;
	}
	return retorno;
}



int Arcade_setIdSalon(Arcade* this,int idSalon)
{
	int retorno = -1;

	if (this != NULL && idSalon > 0)
	{
		this->idSalon = idSalon;
		retorno = 0;
	}
	return retorno;

}
int Arcade_getIdSalon(Arcade* this,int* idSalon)
{
	int retorno = -1;

	if (this != NULL && idSalon != NULL)
	{
		*idSalon = this->idSalon;
		retorno = 0;
	}
	return retorno;
}


int Arcade_setIdJuego(Arcade* this,int idJuego)
{
	int retorno = -1;

	if (this != NULL && idJuego > 0)
	{
		this->idJuego = idJuego;
		retorno = 0;
	}
	return retorno;

}
int Arcade_getIdJuego(Arcade* this,int* idJuego)
{
	int retorno = -1;

	if (this != NULL && idJuego != NULL)
	{
		*idJuego = this->idJuego;
		retorno = 0;
	}
	return retorno;
}


void Arcade_ImprimirUno(Arcade* this, int tipo)
{

	int id;
	char nacionalidad[50];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadMaximaFichas;

	//// EL CONTROLER IMPRIME EL NOMBRE DEL SALON Y EL NOMBRE DEL JUEGO?

	char auxTipo[15];
	if (this != NULL)
	{
			if(!Arcade_getId(this, &id) && !Arcade_getNacionalidad(this, nacionalidad) && !Arcade_getTipoSonido(this, &tipoSonido)
					&& !Arcade_getCantidadJugadores(this, &cantidadJugadores)&& !Arcade_getCapacidadMaximaFichas(this, &capacidadMaximaFichas)
					&& (tipo > 0 && tipo < 4) && !convertirTipoSonidoChar(tipoSonido, auxTipo))
			{
				/// NO TIENE SALTO DE LINEA AL FINAL PARA QUE SE PUEDA CONCATENAR CON LA PARTE DE AFUERA
				switch(tipo)
				{
				case 1:
					printf("%d\t%-10s\t%-6s\t%d Jugadores\t%-16d", id, nacionalidad, auxTipo, cantidadJugadores, capacidadMaximaFichas);
					break;
				case 2:
					printf("%-6d\t%d Jugadores\t\t %-15d", id, cantidadJugadores, capacidadMaximaFichas);
					break;
				case 3:
					printf("%-8d%d Jugadores\t",id, cantidadJugadores);
					break;
				}
			}
	}
}


Arcade* Arcade_addArcade(void)
{
	char nacionalidad[50];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadMaximaFichas;

	//PEDIR ESTO POR RELACIONES
	char id[5];
	char idSalon[5];
	char idJuego[5];

	int auxJugadores;

	char auxTipoSonido[10];
	char auxCantidadJugadores[5];
	char auxCapacidadMaximaFicha[5];
	//int auxId;
	int banderaCompleto = 1;
	Arcade* pAux = NULL;


	if(!utn_getString("Ingrese la nacionalidad del Arcade: ", "\nEl dato ingresado no es valido", 3, sizeof(nacionalidad),nacionalidad))
	{
		if(!utn_GetNumero("Ingrese el tipo de Audio ('1' MONO, '2' STEREO): ", 3, 0, 3, "\nLa opcion no es valida", &tipoSonido))
		{
			if(!utn_GetNumero("Ingrese la cantidad de jugadores ('1' Un solo jugador, '2' Dos Jugadores, '3', Cuatro Jugadores, '4', Ocho Jugadores)\nOpcion: ", 3, 0, 5, "\nEsa opcion no es valida\n", &cantidadJugadores))
			{
				if(!utn_GetNumero("Ingrese la capacidad de fichas del Arcade: ", 3, 100, 10000, "\nLa cantidad Maxima no es valida. (entre 100 y 10.000)", &capacidadMaximaFichas))
				{

						auxJugadores = convertirCantidadJugadores(cantidadJugadores);
						if(sprintf(id,"%d",16) && sprintf(idSalon,"%d",10) && sprintf(idJuego,"%d",14) && sprintf(auxCantidadJugadores,"%d",auxJugadores)
								&& sprintf(auxCapacidadMaximaFicha,"%d",capacidadMaximaFichas) && !convertirTipoSonidoChar(tipoSonido, auxTipoSonido))
						{
							pAux = Arcade_newParametros(id, nacionalidad, auxTipoSonido, auxCantidadJugadores, auxCapacidadMaximaFicha, idSalon, idJuego);
							if(pAux != NULL)
							{
								banderaCompleto = 0;
							}
						}
				}
			}
		}

	}
	if(banderaCompleto)
	{
		Arcade_delete(pAux);
		pAux = NULL;
	}
	return pAux;
}

int Arcade_parametrosChar(Arcade* this,char* idStr, char* nacionalidadStr, char* tipoSonidoStr, char* cantidadJugadoresStr, char* capacidadFichasStr, char* idSalonStr, char* idJuegoStr)
{
	int retorno = -1;
	int auxId;
	int auxSonido;
	int auxJugadores;
	int auxMaxFichas;
	int auxIdSalon;
	int auxIdJuego;

	if(this != NULL && idStr != NULL && nacionalidadStr != NULL && tipoSonidoStr != NULL && cantidadJugadoresStr != NULL
			&& capacidadFichasStr != NULL && idSalonStr != NULL && idJuegoStr != NULL)
	{
		if(!Arcade_getNacionalidad(this, nacionalidadStr) && !Arcade_getId(this, &auxId) && !Arcade_getTipoSonido(this, &auxSonido)
				&& !Arcade_getCantidadJugadores(this, &auxJugadores) && !Arcade_getCapacidadMaximaFichas(this, &auxMaxFichas)
				&& !Arcade_getIdSalon(this, &auxIdSalon) && !Arcade_getIdJuego(this, &auxIdJuego))
		{
			if(sprintf(idStr,"%d",auxId) && !convertirTipoSonidoChar(auxSonido, tipoSonidoStr) && sprintf(cantidadJugadoresStr,"%d",auxJugadores) != -1
					&& sprintf(capacidadFichasStr,"%d",auxMaxFichas) != -1 && sprintf(idSalonStr,"%d",auxIdSalon) != -1 && sprintf(idJuegoStr,"%d",auxIdJuego) != -1)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}



///PARA FUNCION SORT

int Arcade_criteroPorSalon(void* ArcadeA, void* ArcadeB)
{
	int retorno = 0;
	int auxIdA;
	int auxIdB;

	Arcade* pAuxA;
	Arcade* pAuxB;

	if(ArcadeA != NULL && ArcadeB != NULL)
	{
		pAuxA = (Arcade*)ArcadeA;
		pAuxB = (Arcade*)ArcadeB;
		if(!Arcade_getIdSalon(pAuxA, &auxIdA) && !Arcade_getIdSalon(pAuxB, &auxIdB))
		{
			if(auxIdA > auxIdB)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int Arcade_criteroJugadores(void* ArcadeA, void* ArcadeB)
{
	int retorno = 0;
	int auxCantidadA;
	int auxcantidadB;

	Arcade* pAuxA;
	Arcade* pAuxB;

	if(ArcadeA != NULL && ArcadeB != NULL)
	{
		pAuxA = (Arcade*)ArcadeA;
		pAuxB = (Arcade*)ArcadeB;
		if(!Arcade_getCantidadJugadores(pAuxA, &auxCantidadA) && !Arcade_getCantidadJugadores(pAuxB, &auxcantidadB))
		{
			if(auxCantidadA > auxcantidadB)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int Arcade_criteroNacionalidad(void* ArcadeA, void* ArcadeB)
{
	int retorno = 0;
	char auxNacionalidadA[50];
	char auxNacionalidadB[50];

	Arcade* pAuxA;
	Arcade* pAuxB;

	if(ArcadeA != NULL && ArcadeB != NULL)
	{
		pAuxA = (Arcade*)ArcadeA;
		pAuxB = (Arcade*)ArcadeB;
		if(!Arcade_getNacionalidad(pAuxA, auxNacionalidadA) && !Arcade_getNacionalidad(pAuxB, auxNacionalidadB))
		{
			if(strncmp(auxNacionalidadA,auxNacionalidadB,sizeof(auxNacionalidadA)) < 0)
			{
				retorno = -1;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Arcade_criteroIdJuego(void* ArcadeA, void* ArcadeB)
{
	int retorno = 0;
	int auxIdJuegoA;
	int auxIdJuegoB;

	Arcade* pAuxA;
	Arcade* pAuxB;

	if(ArcadeA != NULL && ArcadeB != NULL)
	{
		pAuxA = (Arcade*)ArcadeA;
		pAuxB = (Arcade*)ArcadeB;
		if(!Arcade_getIdJuego(pAuxA, &auxIdJuegoA) && !Arcade_getIdJuego(pAuxB, &auxIdJuegoB))
		{
			if(auxIdJuegoA > auxIdJuegoB)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}


///FILTER

int Arcade_filterByNacionalidadJapon(void* ArcadeA)
{
	int retorno = 0;

	char auxNacionalidadA[50];
	Arcade* pAuxA;

	if(ArcadeA != NULL)
	{
		pAuxA = (Arcade*)ArcadeA;

		if(!Arcade_getNacionalidad(pAuxA, auxNacionalidadA))
		{
			if(strncmp(auxNacionalidadA,"Japan",sizeof(auxNacionalidadA)) == 0)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}
