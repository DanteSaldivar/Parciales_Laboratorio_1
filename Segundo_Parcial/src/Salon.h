/*
 *
 * Salon.h
 *
 */

#ifndef SALON_H_
#define SALON_H_
#include "Biblioteca.h"
#include "Parser.h"
#include "LinkedList.h"
#include "Controller.h"
typedef struct
{
	int id;
	char nombre[50];
	char direccion[50];
	int tipoSalon;

}Salon;

Salon* Salon_new();
Salon*Salon_newParametros(char *idStr, char *nombreStr, char *direccionStr, char *tipoSalonStr);
void Salon_delete(Salon* this);

int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);

int Salon_setNombre(Salon* this,char* nombre);
int Salon_getNombre(Salon* this,char* nombre);

int Salon_setDireccion(Salon* this,char* direccion);
int Salon_getDireccion(Salon* this,char* direccion);


int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_getTipoSalon(Salon* this,int* tipoSalon);



Salon* Salon_getById(LinkedList* pArrayListSalon, int id);
Salon* Salon_addSalon(void);
void Salon_ImprimirUno(Salon *this, int tipo);
int Salon_findLastId(char* path,char* pathLastId);
int Salon_SetLastId(char* pathLastId);


int Salon_loadSalonFromText(char* pathSalon, LinkedList* pArrayListSalon);
int Salon_saveSalonAsText(char* pathSalon, LinkedList* pArrayListSalon);
int Salon_parametrosChar(Salon* this,char *idStr, char *nombreStr, char *direccionStr, char *tipoSalonStr);

///PARA FUNCION SORT




#endif /* SALON_H_ */
