/*
 * Salon.c
 *
 */

#include "Salon.h"

Salon* Salon_new(void)
{
	Salon *auxiliarP = NULL;

	auxiliarP = (Salon*) malloc(sizeof(Salon));
	return auxiliarP;
}

Salon* Salon_getById(LinkedList* pArrayListSalon, int id)
{
	Salon* pAux = NULL;
	int lengthArray;
	int auxId;

	lengthArray = ll_len(pArrayListSalon);

	if(pArrayListSalon != NULL && id > 0)
	{
		for(int i = 0; i < lengthArray; i++)
		{
			pAux = (Salon*)ll_get(pArrayListSalon, i);
			if(pAux != NULL)
			{

				Salon_getId(pAux, &auxId);
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

Salon*Salon_newParametros(char *idStr, char *nombreStr, char *direccionStr, char *tipoSalonStr)
{
	Salon *auxiliar = Salon_new();
	int banderaCompletado = 0;
	int auxTipo;


	if (auxiliar != NULL)
	{
		if (esNumerica(idStr, sizeof(idStr)) && esNombre(nombreStr, sizeof(nombreStr)) && esNombre(tipoSalonStr, sizeof(tipoSalonStr)) &&
				esAlfaNumerica(direccionStr, sizeof(direccionStr)))
		{

			if(!Salon_setId(auxiliar, atoi(idStr)) && !Salon_setNombre(auxiliar, nombreStr) && !Salon_setDireccion(auxiliar, direccionStr))
			{
				auxTipo = convertirTipoSalonInt(tipoSalonStr);


				if(!Salon_setTipoSalon(auxiliar, auxTipo))
				{
					banderaCompletado = 1;
				}
			}
		}
	}
	if (banderaCompletado == 0)
	{
		Salon_delete(auxiliar);
		auxiliar = NULL;
	}

	return auxiliar;
}

void Salon_ImprimirUno(Salon *this, int tipo)
{
	int id;
	char nombre[50];
	char direccion[50];
	int TipoSalon;

	char auxTipo[15];
	if (this != NULL)
	{
			if(!Salon_getId(this, &id) && !Salon_getNombre(this, nombre) && !Salon_getDireccion(this, direccion)
					&& !Salon_getTipoSalon(this, &TipoSalon)&& !convertirTipoSalonChar(TipoSalon, auxTipo)
					&& (tipo > 0 && tipo < 6))
			{
				///SE PODRIA PONER EN UNA FUNCION APARTE VISTES
				switch(tipo)
				{
				case 1:
					printf("%-15s\t\t%-15s\t\t%s\n", nombre, direccion, auxTipo);
					break;
				case 2:
					printf("%d\t%-15s\t\t%-15s\n", id, nombre, direccion);
					break;
				case 3:
					printf("%d\t%-15s\t\t%-15s\t\t%-15s\n", id, nombre, direccion, auxTipo);
					break;
				case 4:
					printf("%-15d\t%-15s\t%-16s", id, nombre, direccion);
					break;
				case 5:
					printf("%-24s",nombre);
					break;
				}
				if(tipo != 4 && tipo != 5 )
				{
					puts("----------------------------------------------------------------------------------------------------------");
				}
			}
	}

}

void Salon_delete(Salon *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int Salon_setId(Salon *this, int id)
{
	int retorno = -1;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Salon_getId(Salon *this, int *id)
{
	int retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Salon_setNombre(Salon *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int Salon_getNombre(Salon *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Salon_setDireccion(Salon *this, char *Direccion)
{
	int retorno = -1;

	if (this != NULL && Direccion != NULL)
	{
		strcpy(this->direccion, Direccion);
		retorno = 0;

	}
	return retorno;
}
int Salon_getDireccion(Salon *this, char *Direccion)
{
	int retorno = -1;

	if (this != NULL && Direccion != NULL)
	{
		strcpy(Direccion, this->direccion);
		retorno = 0;
	}
	return retorno;
}


int Salon_setTipoSalon(Salon *this, int tipoSalon)
{
	int retorno = -1;

	if (this != NULL && tipoSalon > 0 && tipoSalon < 4)
	{
		this->tipoSalon = tipoSalon;
		retorno = 0;
	}
	return retorno;
}
int Salon_getTipoSalon(Salon *this, int *tipoSalon)
{
	int retorno = -1;
	if (this != NULL && tipoSalon != NULL)
	{
		*tipoSalon = this->tipoSalon;
		retorno = 0;
	}
	return retorno;
}



Salon* Salon_addSalon(void)
{
	char id[5];
	char nombre[50];
	char Direccion[50];
	char tipoSalon[10];

	int auxTipo;
	int auxId;
	int banderaCompleto = 1;
	Salon* pAux = NULL;


	if(!utn_GetAlfaNumerico("Ingrese el nombre del Salon: ", "\nEl nombre no es valido", 3, sizeof(nombre),nombre))
	{
		if(!utn_GetAlfaNumerico("Ingrese la Direccion del Salon: ", "\nLa Direccion no es valido\n", 3, sizeof(Direccion), Direccion))
		{
			if(!utn_GetNumero("Ingrese el tipo Salon ('1'Shopping, '2'Local): ", 3, 0, 3, "\nEsa opcion no es valida\n", &auxTipo))
			{
				convertirTipoSalonChar(auxTipo, tipoSalon);

				auxId = Salon_SetLastId("LastIdSalon.bin");
				sprintf(id,"%d",auxId);

				pAux = Salon_newParametros(id, nombre, Direccion, tipoSalon);
				if(pAux != NULL)
				{
					banderaCompleto = 0;
				}
			}

		}


	}
	if(banderaCompleto)
	{
		Salon_delete(pAux);
		pAux = NULL;
	}
	return pAux;
}

int Salon_parametrosChar(Salon* this,char *idStr, char *nombreStr, char *direccionStr, char *tipoSalonStr)
{
	int retorno = -1;
	int auxId;
	int auxTipo;

	if(this != NULL && idStr != NULL && nombreStr != NULL && direccionStr != NULL && tipoSalonStr != NULL)
	{
		if(!Salon_getNombre(this, nombreStr) && !Salon_getDireccion(this, direccionStr)
				&& !Salon_getId(this, &auxId) && !Salon_getTipoSalon(this, &auxTipo))
		{
			if(!convertirTipoSalonChar(auxTipo, tipoSalonStr))
			{
				sprintf(idStr,"%d",auxId);
				retorno = 0;
			}
		}
	}
	return retorno;
}

///PARA CARGAR Y GUARDAR EN ARCHIVO
int Salon_loadSalonFromText(char* pathSalon, LinkedList* pArrayListSalon)
{
	int retorno = -1;
	if(pathSalon != NULL && pArrayListSalon != NULL)
	{
		FILE* pFile = fopen(pathSalon,"r");
		if(pFile != NULL)
		{
			if(parser_SalonFromText(pFile, pArrayListSalon) == 0)
			{
				fclose(pFile);
				retorno = 0;
			}
		}
	}

	return retorno;
}
int Salon_saveSalonAsText(char* pathSalon, LinkedList* pArrayListSalon)
{
	int retorno = -1;
		if(pathSalon != NULL && pArrayListSalon != NULL && !ll_isEmpty(pArrayListSalon))
		{
			FILE* pFile = fopen(pathSalon,"w");
			if(pFile != NULL)
			{
				if(!parser_SalonToText(pFile, pArrayListSalon))
				{
					fclose(pFile);
					retorno = 0;
				}
			}
		}
	return retorno;
}

///FUNCION PARA ENCONTRAR ID DEL ARCHIVO

int Salon_findLastId(char* path,char* pathLastId)
{
	int retorno = -1;
	int maxId;
	int lengthList;
	Salon* pAux;
	LinkedList* lAux = ll_newLinkedList();
	if(path != NULL && pathLastId != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_SalonFromText(pFile, lAux) == 0)
			{
				lengthList = ll_len(lAux);
				pAux = ll_get(lAux, lengthList - 1);
				if(pAux != NULL)
				{
					Salon_getId(pAux, &maxId);
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
int Salon_SetLastId(char* pathLastId)
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

/// PARA LA FUNCION SORT










