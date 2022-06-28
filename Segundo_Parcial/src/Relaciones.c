/*
 * Relaciones.c
 *
 *  PARA NO ENSUCIA TANTO EL CONTROLLER, ACA HAGO
 *  LAS FUNCIONES QUE NECESITEN LAS OTRAS LISTAS
 *
 */


#include "Relaciones.h"
static int Relaciones_obtenerIdSalon(LinkedList *pArrayListSalon);
static int Relaciones_obtenerIdSalon(LinkedList *pArrayListSalon)
{
	int retorno = 0;
	int auxSalon;
	do {
		if (!utn_GetNumero("Ingresa el ID del salon al que lo deseas agregar (o '0' para listar los salones): ",
				3, -1, 10000, "\nEl numero ingresado no es valido",&auxSalon))
		{
			if (auxSalon == 0)
			{
				controller_ListSalon(pArrayListSalon, 2);
			}
			else
			{
				retorno = auxSalon;
				break;
			}
		}
	} while (auxSalon == 0);

	return retorno;
}
static int Relaciones_obtenerIdJuego(LinkedList* pArrayListJuegos);
static int Relaciones_obtenerIdJuego(LinkedList* pArrayListJuegos)
{
	int retorno = 0;
		int auxJuego;
		do {
			if (!utn_GetNumero("Ingresa el ID del Juego que lo deseas agregar (o '0' para listar los Juegos): ",
					3, -1, 10000, "\nEl numero ingresado no es valido",&auxJuego))
			{
				if (auxJuego == 0)
				{
					controller_ListJuego(pArrayListJuegos, 2);
				}
				else
				{
					retorno = auxJuego;
					break;
				}
			}
		} while (auxJuego == 0);

		return retorno;
}

Arcade* relaciones_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListJuegos)
{
	Arcade* pAux = NULL;
	int auxSalon;
	int auxJuego;
	int auxId;
	if(pArrayListSalon != NULL && pArrayListJuegos)
	{
		pAux = Arcade_addArcade();
		if(pAux != NULL)
		{
			auxSalon = Relaciones_obtenerIdSalon(pArrayListSalon);
			auxJuego = Relaciones_obtenerIdJuego(pArrayListJuegos);
			auxId = relaciones_SetLastId("LastIdArcade.bin");
			puts("hola");
			if(auxSalon != 0 && auxJuego != 0 && auxId != 0 )
			{
				Arcade_setId(pAux, auxId);
				Arcade_setIdSalon(pAux, auxSalon);
				Arcade_setIdJuego(pAux, auxJuego);
			}
		}
	}
	return pAux;
}

int relaciones_imprimirArcade(Arcade* this, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos, int tipo)
{
	int retorno = -1;
	int auxIdSalon;
	int auxIdJuego;

	Salon* auxSalon;
	Juego* auxJuego;
	if(this != NULL && pArrayListSalon != NULL)
	{

		 if(!Arcade_getIdSalon(this, &auxIdSalon) && !Arcade_getIdJuego(this, &auxIdJuego))
		 {
			auxSalon = Salon_getById(pArrayListSalon, auxIdSalon);
			auxJuego = Juego_getById(pArrayListJuegos, auxIdJuego);

			if(auxSalon != NULL)
			{
				switch(tipo)
				{
				case 1:
					Arcade_ImprimirUno(this, 1);
					Salon_ImprimirUno(auxSalon, 4);
					Juego_ImprimirUno(auxJuego, 1);
					break;
				case 2:
					Arcade_ImprimirUno(this, 1);
					if(Juego_ImprimirUno(auxJuego, 1))
					{
						puts("\n");
					}
					break;
				}
			}
		 }


	}
	return retorno;
}


int relaciones_removerArcadeRelacionado(LinkedList* pArrayListArcade, int idSalon)
{
	int retorno = -1;
	int lengthList;
	Arcade* pAux = NULL;
	int idAux;
	int contadorCoincidencias = 0;
	if(pArrayListArcade != NULL && idSalon > 0)
	{
		lengthList = ll_len(pArrayListArcade);

		for(int i = 0; i < lengthList; i++)
		{
			pAux = ll_get(pArrayListArcade, i);
			if(pAux != NULL)
			{
				if(!Arcade_getIdSalon(pAux, &idAux))
				{
					if(idAux == idSalon)
					{
						ll_remove(pArrayListArcade, i);
						contadorCoincidencias++;
					}
				}
			}
		}
		if(contadorCoincidencias == 0)
		{
			puts("El salon no contenia Arcades Asociados.");
		}
		retorno = 0;
	}

	return retorno;
}

int relaciones_editArcade(Arcade* this, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int auxOpcion;
	int auxJugadores;
	int banderaModificacion;
	if(this != NULL && pArrayListJuegos != NULL)
	{
		do
		{
			banderaModificacion = 1;
			if(!utn_GetNumero("Que desea Modificar?\n1)Cantidad Jugadores\n2)Juego que contiene\nOpcion: ", 3, 0, 3, "\nLa opcion Elegida no es valida.\n", &auxOpcion))
			{
				switch(auxOpcion)
				{
				case 1:
					if(!utn_GetNumero("Ingrese la nueva Cantidad de Juegadores ('1' Un solo jugador, '2' Dos Jugadores, '3', Cuatro Jugadores, '4', Ocho Jugadores)\nOpcion: "
							, 3, 0, 5, "\nLa opcion no es valida.\n", &auxOpcion))
					{
						auxJugadores = convertirCantidadJugadores(auxOpcion);
						if(!Arcade_setCantidadJugadores(this, auxJugadores))
						{
							retorno = 0;
							banderaModificacion = 0;
						}
					}
					break;
				case 2:
					controller_ListJuego(pArrayListJuegos, 2);
					if(!utn_GetNumero("Ingrese el ID del juego que desea Agregar: ", 3, 0, 10000, "\nEl numero id no es valido.\n", &auxOpcion))
					{
						if(!Arcade_setIdJuego(this, auxOpcion))
						{
							retorno = 0;
							banderaModificacion = 0;
						}
					}
					break;
				}
			}
			if(banderaModificacion)
			{
				puts("\nError, no se pudo realizar la modificacion.");
			}

		}while(validar_Salida_SN("Desea modificar otro Campo? S/N : ", "\nOpcion no Valida.\n", 3));
	}
	return retorno;
}

///PARA CARGAR Y GUARDAR EN ARCHIVO
int relaciones_saveArcadeAsText(char* pathArcade, LinkedList* pArrayListArcade)
{
	int retorno = -1;
		if(pathArcade != NULL && pArrayListArcade != NULL && !ll_isEmpty(pArrayListArcade))
		{
			FILE* pFile = fopen(pathArcade,"w");
			if(pFile != NULL)
			{
				if(!parser_ArcadeToText(pFile, pArrayListArcade))
				{
					fclose(pFile);
					retorno = 0;
				}
			}
		}
	return retorno;
}
int relaciones_loadArcadeFromText(char* pathArcade, LinkedList* pArrayListArcade)
{
	int retorno = -1;
	if(pathArcade != NULL && pArrayListArcade != NULL)
	{
		FILE* pFile = fopen(pathArcade,"r");
		if(pFile != NULL)
		{
			if(parser_ArcadeFromText(pFile, pArrayListArcade) == 0)
			{
				fclose(pFile);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// PARA ENCONTRAR EL ULTIMO ID
int relaciones_findArcadeLastId(char* path,char* pathLastId)
{
	int retorno = -1;
	int maxId;
	int lengthList;
	Arcade* pAux;
	LinkedList* lAux = ll_newLinkedList();
	if(path != NULL && pathLastId != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_ArcadeFromText(pFile, lAux) == 0)
			{
				lengthList = ll_len(lAux);
				pAux = ll_get(lAux, lengthList - 1);
				if(pAux != NULL)
				{
					Arcade_getId(pAux, &maxId);
					ll_clear(lAux);
					fclose(pFile);
				}
			}
			FILE* pFileLastId = fopen(pathLastId,"wb");
			{
				if(pFileLastId != NULL)
				{
					fwrite(&maxId,sizeof(int),1,pFileLastId);
					fclose(pFileLastId);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
int relaciones_SetLastId(char* pathLastId)
{
	int retorno  = -1;
	int lastId;
	int totalDatos;
	if(pathLastId != NULL)
	{
		FILE* fLastId = fopen(pathLastId,"rb");
		if(fLastId != NULL)
		{
			totalDatos = fread(&lastId,sizeof(int),1,fLastId);
			if(totalDatos == 1)
			{
				retorno = lastId + 1;
				if(!fclose(fLastId))
				{
					fLastId = fopen(pathLastId,"wb");
					if(fLastId != NULL)
					{
						fwrite(&retorno,sizeof(int),1,fLastId);
						fclose(fLastId);
					}
				}

			}
		}
	}
	return retorno;
}

