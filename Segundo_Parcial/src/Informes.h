/*
 * Informes.h
 *
 *
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Controller.h"
#include "Relaciones.h"


int Informes_listarOpcionA(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade);
int informes_listarOpcionB(LinkedList* pArrayListSalon, LinkedList* parrayListArcade, LinkedList* pArrayListJuegos);
int Informes_listarOpcionC(LinkedList* pArrayListSalon);
int Informes_listarOpcionD(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos);
int Informes_ListarOpcionE(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos);
int Informes_ListarOpcionF(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos);
int Informes_listarOpcionG(LinkedList* pArrayListArcade,LinkedList* pArrayListSalon, LinkedList* pArrayListJuegos);

#endif /* INFORMES_H_ */
