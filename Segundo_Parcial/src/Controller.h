/*
 * Controller.h
 *
 *  Created on: 24 jun 2022
 *      Author: Mi PC
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"
#include "Relaciones.h"
#include "Parser.h"

///-----------------------SET ID---------------------------------------///
int controller_findId(char* pathSalon,char* pathSalonLastId,char* pathArcade,char* pathArcadeLastId,char* pathJuegos,char* pathJuegoLastId);


///-----------------------ARCHIVOS-------------------------------------///
int controller_loadFromText(char* pathSalon, LinkedList* pArrayListSalon,char*pathArcade, LinkedList* pArrayListArcade,char* pathJuego, LinkedList* pArrayListJuegos);

int controller_saveSalonAsText(char* pathSalon, LinkedList* pArrayListSalon);
int controller_saveArcadeAsText(char* pathArcade, LinkedList* pArrayListArcade);
int controller_saveJuegoAsText(char* pathJuego, LinkedList* pArrayListJuegos);

///-----------------------SALONES--------------------------------------///
int controller_addSalon(LinkedList* pArrayListSalon);

int controller_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade);

int controller_ListSalon(LinkedList* pArrayListSalon, int tipo);

///-----------------------ARCADE--------------------------------------///
int controller_addArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos);

int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos);

int controller_removeArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon);

int controller_listArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalon,LinkedList* pArrayListJuegos, int tipo);

///-----------------------JUEGO--------------------------------------///

int controller_addJuego(LinkedList* pArrayListJuegos);

int controller_ListJuego(LinkedList* pArrayListJuegos, int tipo);
#endif /* CONTROLLER_H_ */
