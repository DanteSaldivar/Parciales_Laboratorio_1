/*
 ============================================================================
 	 DANTE SALDIVAR
 	 DIVISON H.
 	 PARCIAL_2


Agregar funcion FILTER

 ============================================================================
 */

#include "Controller.h"
#include "Informes.h"


int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int opcionSubMenu;
	int errorInforme = 1;
	LinkedList* listaJuegos = ll_newLinkedList();
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();
	LinkedList* NewLinked = ll_newLinkedList();



	controller_findId("MOCK_SALON.csv", "LastIdSalon.bin", "MOCK_ARCADE.csv", "LastIdArcade.bin", "MOCK_JUEGOS.csv", "LastIdJuego.bin");
	controller_loadFromText("MOCK_SALON.csv", listaSalones, "MOCK_ARCADE.csv", listaArcades, "MOCK_JUEGOS.csv", listaJuegos);

	do
	{
		puts("*********************************************************************************************************************************************");
		if(!utn_GetNumero("\t\tBienvenido\n\nMenu opciones:\nSALON\n1)Alta Salon\n2)Eliminar Salon\n3)Listar Salones\nARCADES\n4)Incorporar Arcade"
				"\n5)Modificar Arcade\n6)Eliminar Arcade\n7)Listar Arcades\nJUEGOS\n8)Agregar Juego\n9)Imprimir Juegos\n\n10)INFORMES\n\n11)Filtrar\n12)Salir\nOpcion: "
				, 3, 0, 12, "\nEror, opcion no Valida.\n", &opcionMenu))
		{
			switch(opcionMenu)
			{
			case 1:
				if(controller_addSalon(listaSalones))
				{
					puts("Ocurrio un Error, no se pudo cargar el Salon.");
				}
				break;
			case 2:
				if(controller_removeSalon(listaSalones, listaArcades))
				{
					puts("No se pudo eliminar el Salon.");
				}
				break;
			case 3:
				if(controller_ListSalon(listaSalones, 1))
				{
					puts("No se pudo listar los Salones.");
				}
				break;
			case 4:
				if(controller_addArcade(listaArcades, listaSalones, listaJuegos))
				{
					puts("Ocurrio un Error, no se pudo cargar el Arcade.");
				}
				break;
			case 5:
				if(controller_editArcade(listaArcades, listaJuegos))
				{
					puts("Error, no se pudo modificar el Arcade.");
				}
				break;
			case 6:
				if(controller_removeArcade(listaArcades, listaSalones))
				{
					puts("Error, no se pudo eliminar el Arcade.");
				}
				break;
			case 7:
				if(controller_listArcade(listaArcades, listaSalones, listaJuegos, 2))
				{
					puts("No se pudo listar los Arcades.");
				}
				break;
			case 8:
				if(controller_addJuego(listaJuegos))
				{
					puts("Ocurrio unerror, no se pudo cargar el Juego.");
				}
				break;
			case 9:
				if(controller_ListJuego(listaJuegos, 2))
				{
					puts("No se pudo listar los Juegos.");
				}
				break;
			case 10:
				do
				{
					puts("*********************************************************************************************************************************************");
					if(!utn_GetNumero("\t\tINFORMES\n1)Listar los salones con más de 4 arcade.\n2)Listar los arcade para más de 2 jugadores.\n"
							"3)Listar la información de un salón en específico.\n4)Listar Salones llenos.\n5)Listar arcades de un salon determinado."
							"\n6)Imprimir el salón con más cantidad de arcade.\n7)Listar arcades MONO/PLATAFORMA.\n8)Salir\nOpcion: ", 3, 0, 9, "\nOpcion no valida.\n", &opcionSubMenu))
					{
						switch(opcionSubMenu)
						{
						case 1:

							if(Informes_listarOpcionA(listaSalones, listaArcades))
							{
								errorInforme = 0;
							}
							break;
						case 2:
							if(informes_listarOpcionB(listaSalones, listaArcades, listaJuegos))
							{
								errorInforme = 0;
							}
							break;
						case 3:
							if(Informes_listarOpcionC(listaSalones))
							{
								errorInforme = 0;
							}
							break;
						case 4:
							if(Informes_listarOpcionD(listaSalones, listaArcades, listaJuegos))
							{
								errorInforme = 0;
							}
							break;
						case 5:
							if(Informes_ListarOpcionE(listaSalones, listaArcades, listaJuegos))
							{
								errorInforme = 0;
							}
							break;
						case 6:
							if(Informes_ListarOpcionF(listaSalones, listaArcades, listaJuegos))
							{
								errorInforme = 0;
							}
							break;
						case 7:
							if(Informes_listarOpcionG(listaArcades, listaSalones, listaJuegos))
							{
								errorInforme = 0;
							}
							break;
						}
						if(!errorInforme)
						{
							puts("No se pudo recopilar los datos para el informe.");
							errorInforme = 1;
						}
					}

				}while(opcionSubMenu != 8);
				break;
			case 11:
				 NewLinked = ll_filter(listaArcades, Arcade_filterByNacionalidadJapon);

				controller_listArcade(NewLinked, listaSalones, listaJuegos, 1);
				break;
			}

		}
		else
		{
			break; ///PARA QUE DEJE DE ITERAR
		}
	Juego_saveJuegoAsText("MOCK_JUEGOS.csv", listaJuegos);
	Salon_saveSalonAsText("MOCK_SALON.csv", listaSalones);
	relaciones_saveArcadeAsText("MOCK_ARCADE.csv", listaArcades);

	}while(opcionMenu != 12);
	return 0;
}

/*
	Juego_saveJuegoAsText("Lista_Juegos.txt", listaJuegos);
	Salon_saveSalonAsText("Lista_Salones.txt", listaSalones);
	relaciones_saveArcadeAsText("Lista_Arcades.txt", listaArcades);
	*/
