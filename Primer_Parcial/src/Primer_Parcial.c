/*
 ============================================================================
 Name        : Primer_Parcial.c
 Author      : Dante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Relaciones.h"

#define MAX_USERS 15
#define MAX_PRODUCTS 1000
#define MAX_TRACKING 1000

int main(void)
{
	setbuf(stdout, NULL);

	int respuestaPrincipal;
	int respuestaSubMenu;
	int banderaLogin;
	short int banderaDeTipo = 0;
	int banderaConId = 0;
	int auxiliarVentas;
	eUsuario arrayUsuarios[MAX_USERS];
	eProducto arrayProductos[MAX_PRODUCTS];
	eTracking arrayTracking[MAX_TRACKING];

	eUsuario_inicializarUsuarios(arrayUsuarios, MAX_USERS);
	eProducto_InicializarProductos(arrayProductos, MAX_PRODUCTS);
	eTracking_InicializarTrackings(arrayTracking, MAX_TRACKING);

	do
	{
		mostrarTituloMenu(1);
		banderaLogin = 0;
		utn_GetNumero("\n1) INGRESAR\n2)REGISTRARSE\n\n3)Altas Forzadas\n\n0)SALIR\n\nOpcion: ", 3, -1, 3, "\nla Opcion no es valida\n", &respuestaPrincipal);

		switch (respuestaPrincipal)
		{
		case 1:
			if (!eUsuario_InicioDeSesion(arrayUsuarios, MAX_USERS, &banderaConId, &banderaDeTipo))
			{
				banderaLogin = 1;
			}
			else
			{
				puts("No se pudo Iniciar Sesion");
			}
			while (banderaLogin)
			{
				switch (banderaDeTipo)
				{
				case ADMIN:
					do
					{
						mostrarTituloMenu(3);
						if (!utn_GetNumero(
								"\n1)Listar todos los Usuarios\n2)Listar todos los productos por categoria\n3)Baja de un producto\n4)Baja de un usuario\n5)Ver Tracking Global\n6)Salir\nOpcion : ", 3,
								0, 7, "\nla Opcion no es valida\n", &respuestaSubMenu))
						{
							switch(respuestaSubMenu)
							{
							case 1:
								eUsuario_ImprimirUsuarios(arrayUsuarios, MAX_USERS);
								break;
							case 2:
								eProducto_SortProducto(arrayProductos, MAX_PRODUCTS, -1);
								eProducto_ImprimirProductos(arrayProductos, MAX_PRODUCTS);
								break;
							case 3:
								eProducto_RemoverProducto(arrayProductos, MAX_PRODUCTS);
								break;
							case 4:
								eUsuario_DarDeBaja(arrayUsuarios, MAX_USERS);
								break;
							case 5:
								eTracking_ImprimirTrackings(arrayTracking, MAX_TRACKING);
								break;
							}
						}

					} while (respuestaSubMenu != 6);
					break;
				case USUARIO:
					do
					{
						mostrarTituloMenu(2);
						if (!utn_GetNumero("\n1)Comprar\n2)Vender\n3)Estado de compras\n4)Estado de Ventas\n\n5)Salir\nOpcion : ", 3, 0, 6, "\nla Opcion no es valida\n", &respuestaSubMenu))
						{
							switch (respuestaSubMenu)
							{
							case 1:
								eRelaciones_AltaCompra(arrayUsuarios, MAX_USERS, arrayProductos, MAX_PRODUCTS, arrayTracking, MAX_TRACKING, banderaConId);
								break;
							case 2:
								eProducto_Alta(arrayProductos, MAX_PRODUCTS, banderaConId);
								break;
							case 3:
								eRelaciones_MostrarEstadoCompra(arrayUsuarios, MAX_USERS, arrayProductos, MAX_PRODUCTS, arrayTracking, MAX_TRACKING, banderaConId);
								break;
							case 4:
								if (!utn_GetNumero("1)Listado de ventas finalizadas.\n2)Ver Productos", 3, 0, 3, "Esa opcion no valida\n", &auxiliarVentas))
								{
									switch (auxiliarVentas)
									{
									case 1:
										eRelaciones_MostrarEstadoVentas(arrayUsuarios, MAX_USERS, arrayProductos, MAX_PRODUCTS, arrayTracking, MAX_TRACKING, banderaConId);
										break;
									case 2:
										eProducto_ImprimirProductosPorUser(arrayProductos, MAX_PRODUCTS, banderaConId);
										break;
									}
								}
								break;
							}
						}
					} while (respuestaSubMenu != 5);
					break;
				}
				break;
				case 2:
				eUsuario_Alta(arrayUsuarios, MAX_USERS);
				break;
				case 3:
					eUsuario_Hardcodeo(arrayUsuarios, MAX_USERS);
					eProducto_Hardcodeo(arrayProductos, MAX_PRODUCTS);
					break;
			}
		}
	} while (respuestaPrincipal != 0);

	return 0;
}
