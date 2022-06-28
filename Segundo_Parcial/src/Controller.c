/*
 * Controller.c
 *
 *	[O Relaciones.c]
 *
 */

#include "Controller.h"


////------------------------------------------------------------SALONES----------------------------------------------------///
int controller_addSalon(LinkedList* pArrayListSalon)
{
	int retorno = -1;
	Salon* pAuxiliar;

	if(pArrayListSalon != NULL)
	{
		puts("*********************************************************************************************************************************************");
		pAuxiliar = Salon_addSalon();
		if(pAuxiliar != NULL)
		{
			ll_add(pArrayListSalon, pAuxiliar);
			puts("ID\tNOMBRE\t\t\tDIRECCION\t\tTIPO");
			puts("----------------------------------------------------------------------------------------------------------");
			Salon_ImprimirUno(pAuxiliar, 3);
			retorno = 0;
		}
	}
    return retorno;
}


int controller_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade)
{
	int retorno = -1;
	int auxId;
	int auxIndex;
	Salon* pAux = NULL;

	if(pArrayListSalon != NULL && pArrayListArcade != NULL && !ll_isEmpty(pArrayListSalon))
	{
		puts("----------------------------------------------------------------------------------------------------------");
		if(!utn_GetNumero("Ingrese el ID del Salon que desea Eliminar: ", 3, 0, 10000, "\nNumero no valido\n", &auxId))
		{
			pAux = (Salon*)Salon_getById(pArrayListSalon, auxId);
			if(pAux != NULL)
			{
				auxIndex = ll_indexOf(pArrayListSalon, pAux);
				if(auxIndex > -1)
				{
					puts("\nNOMBRE\t\t\tDIRECCION\t\tTIPO");
					puts("----------------------------------------------------------------------------------------------------------");
					Salon_ImprimirUno(pAux,1);

					if(validar_Salida_SN("\nEsta seguro que quiere eliminar el Salon? S/N ", "\nOpcion no valida\n", 3))
					{
						ll_remove(pArrayListSalon, auxIndex);
						if(relaciones_removerArcadeRelacionado(pArrayListArcade, auxId))
						{
							puts("No se pudieron remover los Arcades.");
						}
						retorno = 0;
					}
				}
			}
		}
	}
    return retorno;
}


int controller_ListSalon(LinkedList* pArrayListSalon, int tipo)
{
	int retorno = -1;
	int banderaPrimero = 1;
	Salon* pAux;

	int lengthArray;

	lengthArray = ll_len(pArrayListSalon);
	if(pArrayListSalon != NULL && tipo > 0 && tipo < 4)
	{

		puts("*********************************************************************************************************************************************");
		for(int i = 0; i < lengthArray;i++)
		{
			pAux = ll_get(pArrayListSalon, i);
			if(pAux != NULL)
			{
				if (banderaPrimero)
				{
					///SE PODRIA PONER EN UNA FUNCION APARTE VISTES
					switch(tipo)
					{
					case 1:
						puts("NOMBRE\t\t\tDIRECCION\t\tTIPO");
						break;
					case 2:
						puts("ID\tNOMBRE\t\t\tDIRECCION");
						break;
					case 3:
						puts("ID\tNOMBRE\t\t\tDIRECCION\t\tTIPO");
						break;
					}
					puts("----------------------------------------------------------------------------------------------------------");
					banderaPrimero = 0;
				}

				Salon_ImprimirUno(pAux,tipo);
				retorno = 0;
			}
		}

	}

	return retorno;
}
////------------------------------------------------------------ARCADES----------------------------------------------------///


int controller_addArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	Arcade* pAuxiliar = NULL;

	if(pArrayListArcade != NULL)
	{
		puts("*********************************************************************************************************************************************");
		pAuxiliar = relaciones_addArcade(pArrayListSalon,pArrayListJuegos);
		if(pAuxiliar != NULL)
		{
			ll_add(pArrayListArcade, pAuxiliar);
			retorno = 0;
		}
	}
    return retorno;
}


int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	Arcade* pAux = NULL;
	int auxId;

	if(pArrayListArcade != NULL && pArrayListJuegos != NULL && !ll_isEmpty(pArrayListArcade))
	{
		puts("*********************************************************************************************************************************************");
			if(!utn_GetNumero("Ingrese el ID del Arcade a modificar: ", 3, 0, 10000, "\nNumero no valido\n", &auxId))
			{
				pAux = Arcade_getById(pArrayListArcade, auxId);

				if(pAux != NULL)
				{
					puts("ID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS");
					puts("---------------------------------------------------------------------------------------------------------------------------------------------");
					Arcade_ImprimirUno(pAux,1);
					puts("\n---------------------------------------------------------------------------------------------------------------------------------------------");
					if(!relaciones_editArcade(pAux,pArrayListJuegos))
					{
						retorno = 0;
					}
				}
			}
	}

	return retorno;
}

int controller_removeArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon)
{
	int retorno = -1;
	int auxIdA;
	int auxIdS;
	int auxIndex;
	Arcade* pAux = NULL;
	Salon* pAuxSalon = NULL;

	if(pArrayListArcade != NULL && !ll_isEmpty(pArrayListSalon) && pArrayListSalon != NULL)
	{
		puts("*********************************************************************************************************************************************");
		if(!utn_GetNumero("Ingrese el ID del Arcade que desea Eliminar: ", 3, 0, 10000, "\nNumero no valido\n", &auxIdA))
		{
			pAux = (Arcade*)Arcade_getById(pArrayListArcade, auxIdA);
			Arcade_getIdSalon(pAux, &auxIdS);
			pAuxSalon = (Salon*)Salon_getById(pArrayListSalon, auxIdS);
			if(pAux != NULL && pAuxSalon != NULL)
			{
				auxIndex = ll_indexOf(pArrayListArcade, pAux);
				if(auxIndex > -1)
				{
					puts("\nID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS\tID_SALON\tNOMBRE\t\tDIRECCION");
					puts("----------------------------------------------------------------------------------------------------------");
					Arcade_ImprimirUno(pAux,1);
					Salon_ImprimirUno(pAuxSalon, 4);

					if(validar_Salida_SN("\nEsta seguro que quiere eliminar el Arcade? S/N ", "\nOpcion no valida\n", 3))
					{
						ll_remove(pArrayListArcade, auxIndex);
						Arcade_delete(pAux);
						retorno = 0;
					}

				}
			}
		}
	}
	return retorno;

}


int controller_listArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos, int tipo)
{
	int retorno = -1;
	int banderaPrimero = 1;
	Arcade* pAux;

	int lengthArray;

	lengthArray = ll_len(pArrayListArcade);

	if(pArrayListArcade != NULL && pArrayListSalon != NULL&& tipo > 0 && tipo < 4)
	{
		puts("*********************************************************************************************************************************************");
		for(int i = 0; i < lengthArray;i++)
		{
			pAux = ll_get(pArrayListArcade, i);

			if(pAux != NULL)
			{
				if (banderaPrimero)
				{
					///SE PODRIA PONER EN UNA FUNCION APARTE VISTES
					switch(tipo)
					{
					case 1:
						puts("ID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS\tID_SALON\tNOMBRE\t\tDIRECCION\tJUEGO\t\tGENERO");
						break;
					case 2:
						puts("ID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS\tJUEGO\t\tGENERO");
						break;
					case 3:
						puts("ID\tMAX JUGADORES\tNOMBRE SALON\tDIRECCION\tJUEGO\t\tGENERO");
						break;
					}
					puts("---------------------------------------------------------------------------------------------------------------------------------------------");

					banderaPrimero = 0;
				}
				relaciones_imprimirArcade(pAux, pArrayListSalon,pArrayListJuegos, tipo);
				retorno = 0;
			}
		}

	}

	return retorno;

}

////------------------------------------------------------------JUEGOS----------------------------------------------------///

int controller_addJuego(LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	Juego* pAuxiliar;

	if(pArrayListJuegos != NULL)
	{
		puts("*********************************************************************************************************************************************");
		pAuxiliar = Juego_addJuego();
		if(pAuxiliar != NULL)
		{
			ll_add(pArrayListJuegos, pAuxiliar);
			puts("ID\tNOMBRE\t\tEMPRESA\t\tGENERO");
			puts("----------------------------------------------------------------------------------------------------------");
			Juego_ImprimirUno(pAuxiliar, 2);
			retorno = 0;
		}
	}
	return retorno;
}


int controller_ListJuego(LinkedList* pArrayListJuegos, int tipo)
{
	int retorno = -1;
	int banderaPrimero = 1;
	Juego* pAux;

	int lengthArray;

	lengthArray = ll_len(pArrayListJuegos);

	if(pArrayListJuegos != NULL && pArrayListJuegos != NULL&& tipo > 0 && tipo < 3)
	{
		puts("*********************************************************************************************************************************************");
		for(int i = 0; i < lengthArray;i++)
		{
			pAux = ll_get(pArrayListJuegos, i);

			if(pAux != NULL)
			{
				if (banderaPrimero)
				{
					///SE PODRIA PONER EN UNA FUNCION APARTE VISTES
					switch(tipo)
					{
					case 1:
						puts("NOMBRE\t\tGENERO");
						break;
					case 2:
						puts("ID\tNOMBRE\t\tEMPRESA\t\tGENERO");
						break;
					}
					puts("----------------------------------------------------------------------------------------------------------");
					banderaPrimero = 0;
				}
				Juego_ImprimirUno(pAux, tipo);
				retorno = 0;
			}
		}
	}

	return retorno;
}

///FUNCION QUE BUSCA LOS ID

int controller_SetLastId(char* pathLastId)
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

////------------------------------------------------------------ARCHIVOS----------------------------------------------------///
int controller_loadFromText(char* pathSalon, LinkedList* pArrayListSalon,char*pathArcade, LinkedList* pArrayListArcade,char* pathJuego, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	if(pathSalon != NULL && pArrayListSalon != NULL && pathArcade != NULL && pArrayListArcade != NULL && pathJuego != NULL && pArrayListJuegos != NULL)
	{
		if(!relaciones_loadArcadeFromText(pathArcade, pArrayListArcade) && !Salon_loadSalonFromText(pathSalon, pArrayListSalon) &&!Juego_loadJuegoFromText(pathJuego, pArrayListJuegos))
		{
			retorno = 0;
		}
	}
	return retorno;
}

int controller_findId(char* pathSalon,char* pathSalonLastId,char* pathArcade,char* pathArcadeLastId,char* pathJuegos,char* pathJuegoLastId)
{
	int retorno = -1;
	if(pathSalon != NULL && pathSalonLastId != NULL && pathArcade != NULL && pathArcadeLastId != NULL && pathJuegos != NULL && pathJuegoLastId != NULL)
	{
		if(!relaciones_findArcadeLastId(pathArcade, pathArcadeLastId) && !Salon_findLastId(pathSalon, pathSalonLastId) && !Juego_findLastId(pathJuegos, pathJuegoLastId))
		{
			retorno = 0;
		}

	}
	return retorno;
}






