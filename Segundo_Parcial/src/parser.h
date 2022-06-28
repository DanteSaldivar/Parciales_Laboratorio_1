/*
 *
 * Parser.h
 *
 * */

#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

int parser_SalonFromText(FILE* pFile , LinkedList* pArrayListSalon);
int parser_SalonToText(FILE* pFile , LinkedList* pArrayListSalon);

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);
int parser_ArcadeToText(FILE* pFile , LinkedList* pArrayListArcade);

int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuegos);
int parser_JuegoToText(FILE* pFile , LinkedList* pArrayListJuegos);

#endif /* PARSER_H_ */
