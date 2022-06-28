/*
 * Informes.c
 *
 *  Created on: 28 jun 2022
 *      Author: Mi PC
 */

#include "Informes.h"

int Informes_listarOpcionA(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade)
{
	int retorno = -1;
	int lengthArray;
	int idAux;
	int idSalon;
	int banderaDelPrimero = 1;
	int contadorCoincidencias = 0;
	int banderaPrimeraImpresion = 1;

	Arcade* pAuxArcade = NULL;
	Salon* pAuxSalon = NULL;

	if(pArrayListSalon != NULL && pArrayListArcade != NULL)
	{
		LinkedList* pListAux = ll_clone(pArrayListArcade);
		lengthArray = ll_len(pListAux);
		if(pListAux != NULL)
		{
			ll_sort(pListAux, Arcade_criteroPorSalon, 1);

			for(int i = 0; i < lengthArray; i++)
			{
				pAuxArcade = ll_get(pListAux, i);

				if(!Arcade_getIdSalon(pAuxArcade, &idSalon))
				{

					if(banderaDelPrimero)
					{
						idAux = idSalon;
						banderaDelPrimero = 0;
					}
					else
					{
						if(idSalon == idAux)
						{

							contadorCoincidencias++;
							if(contadorCoincidencias == 3)
							{
								pAuxSalon = Salon_getById(pArrayListSalon, idAux);
								if(pAuxSalon != NULL)
								{
									if(banderaPrimeraImpresion)
									{
										puts("ID\tNOMBRE\t\t\tDIRECCION");
										banderaPrimeraImpresion = 0;
									}
									Salon_ImprimirUno(pAuxSalon, 2);
								}
							}
						}
						else
						{
							idAux = idSalon;
							contadorCoincidencias = 0;
						}
					}
				}
			}
			ll_clear(pListAux);
			ll_deleteLinkedList(pListAux);
			retorno  = 0;
		}
	}
	return retorno;
}

int informes_listarOpcionB(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
		int lengthArray;
		int auxCantidad;
		int idSalon;
		int idJuego;
		int banderaPrimeraImpresion = 1;

		Arcade* pAuxArcade = NULL;
		Salon* pAuxSalon = NULL;
		Juego* pAuxJuego = NULL;

		if(pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuegos != NULL)
		{
			LinkedList* pListAux = ll_clone(pArrayListArcade);
			lengthArray = ll_len(pListAux);
			if(pListAux != NULL)
			{
				ll_sort(pArrayListArcade, Arcade_criteroJugadores,1);
				for(int i = 0; i < lengthArray; i++)
				{
					pAuxArcade = ll_get(pArrayListArcade, i);
					if(pAuxArcade != NULL)
					{
						if(!Arcade_getCantidadJugadores(pAuxArcade, &auxCantidad))
						{
							if(auxCantidad > 1)
							{
								if(!Arcade_getIdSalon(pAuxArcade, &idSalon) && !Arcade_getIdJuego(pAuxArcade, &idJuego))
								{
									pAuxSalon = Salon_getById(pArrayListSalon, idSalon);
									pAuxJuego = Juego_getById(pArrayListJuegos, idJuego);
									if(banderaPrimeraImpresion)
									{
										puts("ID\tMAX JUGADORES\tNOMBRE SALON\t\tJUEGO\t\tGENERO");
										banderaPrimeraImpresion = 0;
									}
									Arcade_ImprimirUno(pAuxArcade, 3);
									Salon_ImprimirUno(pAuxSalon, 5);
									Juego_ImprimirUno(pAuxJuego, 1);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
return retorno;
}


int Informes_listarOpcionC(LinkedList* pArrayListSalon)
{
	int retorno = -1;
	int auxOpcion;
	if(pArrayListSalon != NULL)
	{
		if(!controller_ListSalon(pArrayListSalon, 2))
		{
			if(!utn_GetNumero("Ingrese el id del Salon del que quiere ver su informacion: ", 3, 0, 10000, "\nOpcion no valida.\n", &auxOpcion))
			{
				Salon* pAux = Salon_getById(pArrayListSalon, auxOpcion);
				if(pAux != NULL)
				{

					puts("\nID\tNOMBRE\t\t\tDIRECCION\t\tTIPO");
					puts("----------------------------------------------------------------------------------------------------------");
					Salon_ImprimirUno(pAux, 3);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int Informes_listarOpcionD(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int lengthList;
	int auxIdSalon;
	int auxIdJuego;
	int auxGenero;
	int banderaDelPrimero = 1;

	int auxId;
	int contadorLaberinto = 0;
	int contadorAventura = 0;
	int contadorPlataforma = 0;


	Arcade* pAuxArcade;
	Salon* pAuxSalon;
	Juego* pAuxJuego;

	if(pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuegos != NULL)
	{
		LinkedList* pListAux = ll_clone(pArrayListArcade);
		lengthList = ll_len(pListAux);
		if(pListAux != NULL)
		{
			ll_sort(pArrayListArcade, Arcade_criteroPorSalon,1);
			for(int i = 0; i < lengthList; i++)
			{
				pAuxArcade = ll_get(pArrayListArcade, i);
				if(!Arcade_getIdSalon(pAuxArcade, &auxIdSalon) && !Arcade_getIdJuego(pAuxArcade, &auxIdJuego))
				{
					pAuxSalon = Salon_getById(pArrayListSalon, auxIdSalon);
					pAuxJuego = Juego_getById(pArrayListJuegos, auxIdJuego);
					if(pAuxSalon != NULL && pAuxJuego != NULL)
					{
						if(!Juego_getGenero(pAuxJuego, &auxGenero))
						{
							if(banderaDelPrimero)
							{
								auxId = auxIdSalon;
								banderaDelPrimero = 0;
							}
							if(auxId == auxIdSalon)
							{
								switch(auxGenero)
								{
								case 1:
									contadorPlataforma++;
									break;
								case 2:
									contadorLaberinto++;
									break;
								case 3:
									contadorAventura++;
									break;
								}
								if(contadorPlataforma == 4 && contadorLaberinto == 3 && contadorAventura == 5)
								{
									puts("SALONES LLENOS:\nID\tNOMBRE\t\t\tDIRECCION");
									puts("----------------------------------------------------------------------------------------------------------");
									Salon_ImprimirUno(pAuxSalon, 2);
									retorno = 0;
								}
							}
							else
							{
								contadorPlataforma = 0;
								contadorLaberinto = 0;
								contadorAventura = 0;
								banderaDelPrimero = 1;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int Informes_ListarOpcionE(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int auxRespuesta;
	int auxId;
	int auxIdJuego;
	int lengthList;
	int banderaPrimeraImpresion = 1;

	Arcade* pAuxArcade = NULL;
	Salon* pAuxSalon = NULL;
	Juego* pAuxJuego = NULL;

	if(pArrayListArcade != NULL && pArrayListSalon != NULL && pArrayListJuegos != NULL)
	{
		if(!controller_ListSalon(pArrayListSalon, 2))
		{
			if(!utn_GetNumero("Ingrese el ID del salon del cual quiere ver sus Arcades: ", 3, 0, 10000, "\nEl numero no es valido.\n", &auxRespuesta))
			{
				lengthList = ll_len(pArrayListArcade);

				pAuxSalon = Salon_getById(pArrayListSalon, auxRespuesta);
				if(pAuxSalon != NULL)
				{
					puts("\nID\tNOMBRE\t\t\tDIRECCION\t\tTIPO");
					Salon_ImprimirUno(pAuxSalon, 2);
					puts("----------------------------------------------------------------------------------------------------------");

					for(int i = 0; i < lengthList; i++)
					{
						pAuxArcade = ll_get(pArrayListArcade, i);

						if(pAuxArcade != NULL)
						{
							if(!Arcade_getIdSalon(pAuxArcade, &auxId) && !Arcade_getIdJuego(pAuxArcade, &auxIdJuego))
							{
								pAuxJuego = Juego_getById(pArrayListJuegos, auxIdJuego);
								if(pAuxJuego != NULL)
								{
									if(auxId == auxRespuesta)
									{
										if(banderaPrimeraImpresion)
										{
											puts("ID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS\tJUEGO");
											puts("----------------------------------------------------------------------------------------------------------");
											banderaPrimeraImpresion = 0;
										}
										Arcade_ImprimirUno(pAuxArcade, 1);
										Juego_ImprimirUno(pAuxJuego, 3);
									}
								}
							}
						}
					}

				retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int Informes_ListarOpcionF(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int lengthList;
	int MaxIdSalon;
	int auxIdSalon;
	int auxId;
	int auxIdJuego;
	int contadorArcade = 0;
	int maxArcade = 0;
	int banderaDelPrimero = 1;
	int banderaPrimeraImpresion = 1;

	Arcade* pAuxArcade = NULL;
	Salon* pAuxSalon = NULL;
	Juego* pAuxJuego = NULL;
	if(pArrayListArcade != NULL && pArrayListSalon != NULL && pArrayListJuegos != NULL)
	{
		LinkedList* pAuxList = ll_clone(pArrayListArcade);
		lengthList = ll_len(pAuxList);
		ll_sort(pAuxList, Arcade_criteroPorSalon, 1);

		for(int i = 0; i < lengthList; i++)
		{
			pAuxArcade = ll_get(pAuxList, i);

			if(!Arcade_getIdSalon(pAuxArcade, &auxIdSalon))
			{

				if(banderaDelPrimero)
				{
					auxId = auxIdSalon;
					banderaDelPrimero = 0;
				}

				if(auxIdSalon == auxId)
				{

					contadorArcade++;
					if(contadorArcade > maxArcade)
					{
						maxArcade = contadorArcade;
						MaxIdSalon = auxIdSalon;
					}
				}
				else
				{
					contadorArcade = 0;
					banderaDelPrimero = 1;
				}

			}
		}
		if(maxArcade > 0)
		{
			pAuxSalon = Salon_getById(pArrayListSalon, MaxIdSalon);
			puts("\nID\tNOMBRE\t\t\tDIRECCION\t\tTIPO");
			Salon_ImprimirUno(pAuxSalon, 3);
			puts("ARCADES:\n");
			ll_sort(pAuxList, Arcade_criteroNacionalidad, 0);
			for(int i = 0; i < lengthList; i++)
			{
				pAuxArcade = ll_get(pAuxList, i);
				if(pAuxArcade != NULL)
				{
					if(!Arcade_getIdSalon(pAuxArcade, &auxIdSalon) && !Arcade_getIdJuego(pAuxArcade, &auxIdJuego))
					{
						pAuxJuego = Juego_getById(pArrayListJuegos, auxIdJuego);

						if(pAuxJuego != NULL)
						{
							if(auxIdSalon == MaxIdSalon)
							{
								if(banderaPrimeraImpresion)
								{
									puts("ID\tNACIONALIDAD\tSONIDO\tMAX JUGADORES\tMAX FICHAS\tJUEGO");
									puts("----------------------------------------------------------------------------------------------------------");
									banderaPrimeraImpresion = 0;
								}
								Arcade_ImprimirUno(pAuxArcade, 1);
								Juego_ImprimirUno(pAuxJuego, 3);
							}
						}
					}
				}
			}
			ll_deleteLinkedList(pAuxList);
			retorno = 0;
		}
	}

	return retorno;
}
int Informes_listarOpcionG(LinkedList* pArrayListArcade,LinkedList* pArrayListSalon, LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int lengthList;
	int lengthListArcade;
	int auxTipoSonido;
	int auxGenero;
	int auxIdJuego;
	int auxId;

	Arcade* pAuxArcade;
	Juego* pAuxJuego;

	if(pArrayListArcade != NULL && pArrayListJuegos != NULL && pArrayListSalon != NULL)
	{

		LinkedList* auxJuegos = ll_clone(pArrayListJuegos);
		LinkedList* auxArcade = ll_clone(pArrayListArcade);

		int i;
		int j;
		ll_sort(auxJuegos, Juego_criteroNombre, 1);
		ll_sort(auxArcade, Arcade_criteroIdJuego, 1);

		lengthList = ll_len(auxJuegos);
		lengthListArcade =  ll_len(pArrayListArcade);
		puts("ID ARC\tMAX JUGADORES\tJUEGO\t\tGENERO");
		puts("---------------------------------------------------------------------------------------------------------------------------------------------");
		for(i = 0; i < lengthList; i++)
		{
			pAuxJuego = ll_get(auxJuegos,i);
			if(pAuxJuego != NULL)
			{
				if(!Juego_getGenero(pAuxJuego, &auxGenero) && !Juego_getId(pAuxJuego, &auxId))
				{
					if(auxGenero == 1)
					{
						for(j = 0; j < lengthListArcade; j++)
						{
							pAuxArcade = ll_get(auxArcade, j);
							if(!Arcade_getIdJuego(pAuxArcade, &auxIdJuego))
							{
								if(auxId == auxIdJuego)
								{
									if(!Arcade_getTipoSonido(pAuxArcade, &auxTipoSonido))
									{
										if(auxTipoSonido == 1)
										{
											Arcade_ImprimirUno(pAuxArcade, 3);
											Juego_ImprimirUno(pAuxJuego, 1);
											retorno = 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		ll_deleteLinkedList(auxJuegos);
		ll_deleteLinkedList(auxArcade);

	}
	return retorno;
}
