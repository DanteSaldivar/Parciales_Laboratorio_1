/*
 * Relaciones.h
 *
 *  Created on: 26 jun 2022
 *      Author: Mi PC
 */

#ifndef RELACIONES_H_
#define RELACIONES_H_
#include "Biblioteca.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "Parser.h"
#include "Controller.h"
#include "LinkedList.h"

int relaciones_removerArcadeRelacionado(LinkedList* pArrayListJuegos, int idSalon);

Arcade* relaciones_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListJuegos);

int relaciones_imprimirArcade(Arcade* this, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos, int tipo);

int relaciones_editArcade(Arcade* this, LinkedList* pArrayListJuegos);


///PARA ARCHIVOS
int relaciones_findArcadeLastId(char* path,char* pathLastId);
int relaciones_SetLastId(char* pathLastId);
int relaciones_saveArcadeAsText(char* pathArcade, LinkedList* pArrayListArcade);
int relaciones_loadArcadeFromText(char* pathArcade, LinkedList* pArrayListArcade);

///


#endif /* RELACIONES_H_ */
