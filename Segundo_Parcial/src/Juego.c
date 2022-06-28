/*
 * Juego.c
 *
 *
 */

#include "Juego.h"


Juego* Juego_new(void)
{
	Juego *auxiliarP = NULL;

	auxiliarP = (Juego*) malloc(sizeof(Juego));
	return auxiliarP;
}

Juego* Juego_getById(LinkedList* pArrayListJuegos, int id)
{
	Juego* pAux = NULL;
	int lengthArray;
	int auxId;

	lengthArray = ll_len(pArrayListJuegos);

	if(pArrayListJuegos != NULL && id > 0)
	{
		for(int i = 0; i < lengthArray; i++)
		{
			pAux = (Juego*)ll_get(pArrayListJuegos, i);
			if(pAux != NULL)
			{

				Juego_getId(pAux, &auxId);
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


Juego*Juego_newParametros(char *idStr, char *nombreStr, char *EmpresaStr, char *generoStr)
{
	Juego *auxiliar = Juego_new();
	int banderaCompletado = 0;
	int auxGenero;


	if (auxiliar != NULL)
	{

		if (esNumerica(idStr, sizeof(idStr)) && esAlfaNumerica(nombreStr, sizeof(nombreStr)) && esAlfaNumerica(EmpresaStr, sizeof(EmpresaStr)) &&
			esNombre(generoStr, sizeof(generoStr)))
		{


			if(!Juego_setId(auxiliar, atoi(idStr)) && !Juego_setNombre(auxiliar, nombreStr) && !Juego_setEmpresa(auxiliar, EmpresaStr))
			{
				auxGenero = convertirGeneroInt(generoStr);


				if(!Juego_setGenero(auxiliar, auxGenero))
				{
					banderaCompletado = 1;
				}
			}
		}
	}
	if (banderaCompletado == 0)
	{
		Juego_delete(auxiliar);
		auxiliar = NULL;
	}

	return auxiliar;
}

void Juego_delete(Juego* this)
{
	if (this != NULL)
	{
		free(this);
	}
}



int Juego_setId(Juego* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Juego_getId(Juego* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Juego_setNombre(Juego* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}
int Juego_getNombre(Juego* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}


int Juego_setEmpresa(Juego* this,char* empresa)
{
	int retorno = -1;

	if(this != NULL && empresa != NULL)
	{
		strcpy(this->empresa,empresa);
		retorno = 0;
	}
	return retorno;
}
int Juego_getEmpresa(Juego* this,char* empresa)
{
	int retorno = -1;

	if(this != NULL && empresa != NULL)
	{
		strcpy(empresa,this->empresa);
		retorno = 0;
	}
	return retorno;
}


int Juego_setGenero(Juego* this,int genero)
{
	int retorno = -1;

	if(this != NULL && genero > 0 && genero < 5)
	{
		this->genero = genero;
		retorno = 0;
	}
	return retorno;
}
int Juego_getGenero(Juego* this,int* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL)
	{
		*genero = this->genero;
		retorno = 0;
	}
	return retorno;
}


Juego* Juego_addJuego(void)
{
	char id[5];
	char nombre[50];
	char empresa[50];
	char genero[20];

	int auxGenero;
	int auxId;
	int banderaCompleto = 1;
	Juego* pAux = NULL;


	if(!utn_GetAlfaNumerico("Ingrese el nombre del Juego: ", "\nEl nombre no es valido", 3, sizeof(nombre), nombre))
	{
		if(!utn_GetAlfaNumerico("Ingrese el empresa de la empresa: ", "\nEl nombre no es valido\n", 3, sizeof(empresa), empresa))
		{
			if(!utn_GetNumero("Ingrese el Genero del Juego ('1'Plataforma, '2'Laberinto, '3'Aventura, '4' otro): ", 3, 0, 5, "\nEsa opcion no es valida\n", &auxGenero))
			{
				convertirGeneroChar(auxGenero, genero);

				auxId = Juego_SetLastId("LastIdJuego.bin");
				sprintf(id,"%d",auxId);
				pAux = Juego_newParametros(id, nombre, empresa, genero);
				if(pAux != NULL)
				{
					banderaCompleto = 0;
				}
			}
		}
	}
	if(banderaCompleto)
	{
		Juego_delete(pAux);
		pAux = NULL;
	}
	return pAux;
}

int Juego_ImprimirUno(Juego *this, int tipo)
{
	int retorno = -1;
	int id;
	char nombre[50];
	char empresa[50];
	int genero;

	char auxGenero[15];
	if (this != NULL)
	{
		if(!Juego_getId(this, &id) && !Juego_getNombre(this, nombre) && !Juego_getEmpresa(this, empresa)
				&& !Juego_getGenero(this, &genero) && (tipo > 0 && tipo < 4))
		{
			///SE PODRIA PONER EN UNA FUNCION APARTE VISTES
			convertirGeneroChar(genero, auxGenero);
			switch(tipo)
			{
			case 1:
				printf("%-16s%s\n", nombre, auxGenero);
				puts("---------------------------------------------------------------------------------------------------------------------------------------------");
				break;
			case 2:
				printf("%-8d%-16s%-15s%s\n", id, nombre, empresa,auxGenero );
				puts("----------------------------------------------------------------------------------------------------------");
				break;
			case 3:
				printf("%s\n", nombre);
				puts("----------------------------------------------------------------------------------------------------------");
				break;
			}
			retorno = 0;
		}
	}
	return retorno;
}

int Juego_parametrosChar(Juego* this, char* idStr, char* nombreStr, char* empresaStr, char* generoStr)
{
	int retorno = -1;
	int auxId;
	int auxGenero;

	if(this != NULL && idStr != NULL && nombreStr != NULL && empresaStr != NULL && generoStr != NULL)
	{
		if(!Juego_getId(this, &auxId) && !Juego_getNombre(this, nombreStr) && !Juego_getEmpresa(this, empresaStr) && !Juego_getGenero(this, &auxGenero))
		{
			if(sprintf(idStr,"%d",auxId) != -1 && !convertirGeneroChar(auxGenero, generoStr))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}


///CARGAR Y GUARDAR POR ARCHIVO

int Juego_loadJuegoFromText(char* pathJuego, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	if(pathJuego != NULL && pArrayListJuegos != NULL)
	{
		FILE* pFile = fopen(pathJuego,"r");
		if(pFile != NULL)
		{

			if(parser_JuegoFromText(pFile, pArrayListJuegos) == 0)
			{
				fclose(pFile);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int Juego_saveJuegoAsText(char* pathJuego, LinkedList* pArrayListJuego)
{
	int retorno = -1;
		if(pathJuego != NULL && pArrayListJuego != NULL && !ll_isEmpty(pArrayListJuego))
		{
			FILE* pFile = fopen(pathJuego,"w");
			if(pFile != NULL)
			{
				if(!parser_JuegoToText(pFile, pArrayListJuego))
				{
					fclose(pFile);
					retorno = 0;
				}
			}
		}
	return retorno;
}

///FUNCION PARA LEVANTAR ULTIMO ID
int Juego_findLastId(char* path,char* pathLastId)
{
	int retorno = -1;
	int maxId;
	int lengthList;
	Juego* pAux;
	LinkedList* lAux = ll_newLinkedList();
	if(path != NULL && pathLastId != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_JuegoFromText(pFile, lAux) == 0)
			{
				lengthList = ll_len(lAux);
				pAux = ll_get(lAux, lengthList - 1);
				if(pAux != NULL)
				{
					Juego_getId(pAux, &maxId);
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
int Juego_SetLastId(char* pathLastId)
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

///PARA FUNCION SORT
int Juego_criteroNombre(void* juegoA, void* juegoB)
{
	int retorno = 0;
	char auxNombreA[50];
	char auxNombreB[50];

	Juego* pAuxA;
	Juego* pAuxB;

	if(juegoA != NULL && juegoB != NULL)
	{
		pAuxA = (Juego*)juegoA;
		pAuxB = (Juego*)juegoB;
		if(!Juego_getNombre(pAuxA, auxNombreA) && !Juego_getNombre(pAuxB, auxNombreB))
		{
			if(strncmp(auxNombreA,auxNombreB,sizeof(auxNombreA)) > 0)
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
