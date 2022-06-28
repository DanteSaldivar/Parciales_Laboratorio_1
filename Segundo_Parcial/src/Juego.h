/*
 * Juego.h
 *
 *  Created on: 24 jun 2022
 *      Author: Mi PC
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "Biblioteca.h"
#include "Parser.h"
#include "LinkedList.h"
#include "Controller.h"
typedef struct
{
	int id;
	char nombre[50];
	char empresa[50];
	int genero;

}Juego;

Juego* Juego_new();
Juego*Juego_newParametros(char *idStr, char *nombreStr, char *EmpresaStr, char *generoStr);
void Juego_delete(Juego* this);

int Juego_setId(Juego* this,int id);
int Juego_getId(Juego* this,int* id);

int Juego_setNombre(Juego* this,char* nombre);
int Juego_getNombre(Juego* this,char* nombre);

int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_getEmpresa(Juego* this,char* empresa);


int Juego_setGenero(Juego* this,int genero);
int Juego_getGenero(Juego* this,int* genero);



int Juego_ImprimirUno(Juego *this, int tipo);
Juego* Juego_addJuego(void);
Juego* Juego_getById(LinkedList* pArrayListJuego, int id);

int Juego_findLastId(char* path,char* pathLastId);
int Juego_SetLastId(char* pathLastId);
int Juego_loadJuegoFromText(char* pathJuego, LinkedList* pArrayListJuegos);
int Juego_saveJuegoAsText(char* pathJuego, LinkedList* pArrayListJuego);


int Juego_parametrosChar(Juego* this, char* idStr, char* nombreStr, char* empresaStr, char* generoStr);

///PARA EL SORT
int Juego_criteroNombre(void* juegoA, void* juegoB);

#endif /* JUEGO_H_ */
