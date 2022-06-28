
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \return int
 *
 */

int parser_SalonFromText(FILE* pFile , LinkedList* pArrayListSalon)
{
	int retorno = -1;
	//LA FUNCION FOPEN LO HACE LA QUE LLAMA A ESTA
	char id[5];
	char nombre[50];
	char direccion[50];
	char tipoSalon[20];

	int cantidadDeDatosLeidos;

	if(pFile != NULL && pArrayListSalon != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,direccion,tipoSalon);
		do
		{
			cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,direccion,tipoSalon);

			if(cantidadDeDatosLeidos == 4)
			{
				Salon* auxiliarSalon = Salon_newParametros(id, nombre, direccion, tipoSalon);
				if(auxiliarSalon != NULL)
				{
					ll_add(pArrayListSalon, auxiliarSalon);
					retorno = 0;

				}
			}
		}while(feof(pFile) == 0);
	}

    return retorno;
}
int parser_SalonToText(FILE* pFile , LinkedList* pArrayListSalon)
{
	int retorno = -1;

	char idStr[10];
	char nombreStr[50];
	char direccionStr[50];
	char tipoSalon[10];

	int lengthList;

	lengthList = ll_len(pArrayListSalon);

	Salon* pAux;
	if(pFile != NULL && pArrayListSalon != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s\n","id","name","direction","typeSalon");
		for(int i = 0; i < lengthList; i++)
		{
			pAux = ll_get(pArrayListSalon, i);

			if(pAux != NULL)
			{
				if(!Salon_parametrosChar(pAux, idStr, nombreStr, direccionStr, tipoSalon))
				{
					fprintf(pFile,"%s,%s,%s,%s\n",idStr,nombreStr,direccionStr,tipoSalon);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

///-----------------------------------------------------------------ARCADE---------------------------------------------------------------------------//
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno = -1;
	//LA FUNCION FOPEN LO HACE LA QUE LLAMA A ESTA
	char id[5];
	char nacionalidad[50];
	char tipoSonido[10];//MONO STEREO
	char cantidadJugadores[5]; //PUEDEN SER 1-2-4-6-8
	char capacidadMaximaFichas[5]; //> 0
	char idSalon[5];
	char idJuego[5];

	int cantidadDeDatosLeidos;
	if(pFile != NULL && pArrayListArcade != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,tipoSonido,cantidadJugadores,capacidadMaximaFichas,idSalon,idJuego);
		do
		{
			cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,tipoSonido,cantidadJugadores,capacidadMaximaFichas,idSalon,idJuego);

			if(cantidadDeDatosLeidos == 7)
			{
				Arcade* auxiliarArcade = Arcade_newParametros(id, nacionalidad, tipoSonido, cantidadJugadores, capacidadMaximaFichas, idSalon, idJuego);
				if(auxiliarArcade != NULL)
				{
					ll_add(pArrayListArcade, auxiliarArcade);
					retorno = 0;

				}
			}
		}while(feof(pFile) == 0);
	}

    return retorno;
}


int parser_ArcadeToText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno = -1;

	char idStr[10];
	char nacionalidadStr[50];
	char tipoSonidoStr[10];
	char cantidadJugadoresStr[5];
	char capacidadFichasStr[5];
	char idSalonStr[5];
	char idJuegoStr[5];


	int lengthList;

	lengthList = ll_len(pArrayListArcade);

	Arcade* pAux;
	if(pFile != NULL && pArrayListArcade != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n","id","nation","typeAudio","MaxPlayers","MaxCoins","idSalon","IdGame");
		for(int i = 0; i < lengthList; i++)
		{
			pAux = ll_get(pArrayListArcade, i);

			if(pAux != NULL)
			{
				if(!Arcade_parametrosChar(pAux, idStr, nacionalidadStr, tipoSonidoStr, cantidadJugadoresStr,capacidadFichasStr,idSalonStr,idJuegoStr))
				{
					fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",idStr, nacionalidadStr, tipoSonidoStr, cantidadJugadoresStr,capacidadFichasStr,idSalonStr,idJuegoStr);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

///-----------------------------------------------------------------JUEGOS---------------------------------------------------------------------------//
int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuego)
{
	int retorno = -1;
	//LA FUNCION FOPEN LO HACE LA QUE LLAMA A ESTA
	char id[5];
	char nombre[50];
	char empresa[50];
	char genero[20];

	int cantidadDeDatosLeidos;

	if(pFile != NULL && pArrayListJuego != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empresa,genero);
		do
		{
			cantidadDeDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empresa,genero);
			if(cantidadDeDatosLeidos == 4)
			{


				Juego* auxiliarJuego = Juego_newParametros(id, nombre, empresa, genero);
				if(auxiliarJuego != NULL)
				{
					ll_add(pArrayListJuego, auxiliarJuego);
					retorno = 0;
				}
			}
		}while(feof(pFile) == 0);
	}

    return retorno;
}
int parser_JuegoToText(FILE* pFile , LinkedList* pArrayListJuego)
{
	int retorno = -1;

	char idStr[10];
	char nombreStr[50];
	char empresaStr[50];
	char generoStr[20];

	int lengthList;

	lengthList = ll_len(pArrayListJuego);
	Juego* pAux;
	if(pFile != NULL && pArrayListJuego != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s\n","id","name","company","genre");
		for(int i = 0; i < lengthList; i++)
		{
			pAux = ll_get(pArrayListJuego, i);


			if(pAux != NULL)
			{
				if(!Juego_parametrosChar(pAux, idStr, nombreStr, empresaStr, generoStr))
				{
					fprintf(pFile,"%s,%s,%s,%s\n",idStr,nombreStr,empresaStr,generoStr);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
