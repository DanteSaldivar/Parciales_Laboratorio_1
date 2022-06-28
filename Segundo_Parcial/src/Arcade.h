/*
 * Arcade.h
 *
 *  Created on: 24 jun 2022
 *      Author: Mi PC
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "Biblioteca.h"
#include "LinkedList.h"


typedef struct
{
	int id;
	char nacionalidad[50];
	int tipoSonido;//MONO STEREO
	int cantidadJugadores; //PUEDEN SER 1-2-4-6-8
	int capacidadMaximaFichas; //> 0
	int idSalon;
	int idJuego;

}Arcade;

Arcade* Arcade_new();
void* Arcade_getById(LinkedList* pArrayListArcade, int id);

Arcade* Arcade_newParametros(char* idStr, char* nacionalidadStr, char* tipoSonido, char* cantidadJugadores,char* capacidadMaximaFichas,char* idSalon, char* idJuego);
void Arcade_delete(Arcade* this);

int Arcade_setId(Arcade* this,int id);
int Arcade_getId(Arcade* this,int* id);

int Arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);

int Arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores);
int Arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores);

int Arcade_setCapacidadMaximaFichas(Arcade* this,int cantidadMaximaFichas);
int Arcade_getCapacidadMaximaFichas(Arcade* this, int* cantidadMaximaFichas);

int Arcade_setIdSalon(Arcade* this,int idSalon);
int Arcade_getIdSalon(Arcade* this,int* idSalon);

int Arcade_setIdJuego(Arcade* this,int idJuego);
int Arcade_getIdJuego(Arcade* this,int* idJuego);



Arcade* Arcade_addArcade(void);
void Arcade_ImprimirUno(Arcade* this, int tipo);
int Arcade_editArcade(Arcade *this);


int Arcade_parametrosChar(Arcade* this,char* idStr, char* nacionalidadStr, char* tipoSonidoStr, char* cantidadJugadoresStr, char* capacidadFichasStr, char* idSalonStr, char* idJuegoStr);

///PARA FUNCION SORT

int Arcade_criteroPorSalon(void* ArcadeA, void* ArcadeB);
int Arcade_criteroJugadores(void* ArcadeA, void* ArcadeB);
int Arcade_criteroNacionalidad(void* ArcadeA, void* ArcadeB);
int Arcade_criteroIdJuego(void* ArcadeA, void* ArcadeB);





#endif /* ARCADE_H_ */
