/**
 *  Producto.c
 *
 *
 *
 */

#include "Producto.h"
static int eProducto_ObtenerID(void);
static int eProducto_ObtenerID(void)
{
	static int Producto_IdIncremental = 0;
	return Producto_IdIncremental++;
}

void eProducto_InicializarProductos(eProducto arrayDeProducto[], int length)
{
	int i;

	if (arrayDeProducto != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			arrayDeProducto[i].isEmpty = LIBRE;
		}
	}
}

int eProducto_ObtenerIndexLibre(eProducto arrayProductos[], int length)
{
	int retorno = -1;
	int i;

	if (arrayProductos != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayProductos[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eProducto_BuscarPorId(eProducto arrayProductos[], int length, int ID)
{
	int retorno = -1;
	int i;

	if (arrayProductos != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayProductos[i].idProducto == ID && arrayProductos[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eProducto_ImprimirProducto(eProducto Producto)
{
	char auxiliarCategoria[15];
	char auxiliarEstado[15];
	printf("%4d\t%-25s", Producto.idProducto, Producto.nombreDelProducto);

	if (Producto.stock < 1)
	{
		Producto.isEmpty = SIN_STOCK;
	}
	switch (Producto.isEmpty)
	{
	case 1:
		strncpy(auxiliarEstado, "EN VENTA", sizeof(auxiliarEstado));
		break;
	case -3:
		strncpy(auxiliarEstado, "SIN STOCK", sizeof(auxiliarEstado));
		break;
	}
	switch (Producto.categoria)
	{
	case 1:
		strncpy(auxiliarCategoria, "MODA", sizeof(auxiliarCategoria));
		break;
	case 2:
		strncpy(auxiliarCategoria, "ARTE", sizeof(auxiliarCategoria));
		break;
	case 3:
		strncpy(auxiliarCategoria, "TECNOLOGIA", sizeof(auxiliarCategoria));
		break;
	case 4:
		strncpy(auxiliarCategoria, "DEPORTES", sizeof(auxiliarCategoria));
		break;
	}
	printf("\t%-15s", auxiliarCategoria);
	printf("%10s", auxiliarEstado);
	printf("%10d\n", Producto.stock);
	puts("=================================================================================");
}

int eProducto_ImprimirProductos(eProducto arrayProductos[], int length)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;
	if (arrayProductos != NULL && length)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayProductos[i].isEmpty == OCUPADO || arrayProductos[i].isEmpty == SIN_STOCK)
			{
				if (banderaMensaje)
				{
					puts("\n-----------------------------Lista de Productos----------------------------------");
					printf("%5s%9s\t%33s\t%7s\t%16s\n", "ID", "NOMBRE", "CATEGORIA", "ESTADO", "UNIDADES");
					puts("=================================================================================");
					banderaMensaje = 0;
				}
				eProducto_ImprimirProducto(arrayProductos[i]);
				retorno = 0;
			}
		}

	}
	return retorno;
}

int eProducto_ImprimirProductosPorUser(eProducto arrayProductos[], int length, int ID)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;
	if (arrayProductos != NULL && length)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayProductos[i].isEmpty != LIBRE)
			{
				if (arrayProductos[i].Fk_vendedor == ID && arrayProductos[i].stock > 0)
				{
					if (banderaMensaje)
					{
						puts("\n-----------------------------Lista de Productos----------------------------------");
						printf("%5s%9s\t%33s\t%7s\t%16s\n", "ID", "NOMBRE", "CATEGORIA", "ESTADO", "UNIDADES");
						puts("=================================================================================");
						banderaMensaje = 0;
					}
					eProducto_ImprimirProducto(arrayProductos[i]);
					retorno = 0;
				}
			}
		}

	}
	return retorno;
}

int eProducto_CargarDatos(eProducto *Producto)
{
	int retorno = -1;
	eProducto auxiliar;
	if (Producto != NULL)
	{
		puts("\n-------------Ingrese Los datos del Producto----------------");
		if (!utn_GetAlfaNumerico("Ingrese el nombre del Producto: ", "Ese nombre no es valido\n", 3, 25, auxiliar.nombreDelProducto))
		{
			if (!utn_GetNumeroFlotante("Ingrese su Precio de venta: ", 3, 0, 999999, "El precio no es valido\n", &auxiliar.precio))
			{
				puts("-------------------Categorias----------------------");
				puts("1)MODA\n2)ARTE\n3)ELECTRONICA\n4)DEPORTES");
				if (!utn_GetNumero("Categoria: ", 3, 0, 5, "Su eleccion no es valida\n", &auxiliar.categoria))
				{
					if (!utn_GetNumero("Cuantos productos desea poner en venta? (STOCK): ", 3, 0, MAX_STOCK, "La cantidad no es valida o supera lo permitido\n", &auxiliar.stock))
					{
						*Producto = auxiliar;
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

eProducto eProducto_ModificarUno(eProducto Producto)
{
	eProducto aux;

	return aux;
}

int eProducto_Alta(eProducto arrayProductos[], int length, int ID)
{
	int retorno = -1;
	int indexLibre;
	eProducto auxiliarProducto;

	indexLibre = eProducto_ObtenerIndexLibre(arrayProductos, length);
	if (arrayProductos != NULL && length > 0)
	{
		if (indexLibre > -1)
		{
			//CARGO DATOS NO GENERICOS
			if (!eProducto_CargarDatos(&auxiliarProducto))
			{
				auxiliarProducto.idProducto = eProducto_ObtenerID();
				auxiliarProducto.isEmpty = OCUPADO; //A LA VENTA
				auxiliarProducto.Fk_vendedor = ID;
				arrayProductos[indexLibre] = auxiliarProducto;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int eProducto_RemoverProducto(eProducto arrayProductos[], int length)
{
	int retorno = -1;
	int idProducto;
	int index;
	int banderaAltas;

	if (!eProducto_ImprimirProductos(arrayProductos, length))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID del Producto que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idProducto);

		index = eProducto_BuscarPorId(arrayProductos, length, idProducto);
		while (index == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID del Producto que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idProducto);
			index = eProducto_BuscarPorId(arrayProductos, length, idProducto);
		}
		if (validar_Salida_SN("Esta seguro que quiere dar de BAJA? 'S' continuar , 'N' cancelar", "Opcion no valida\n", 3))
		{
			arrayProductos[index].isEmpty = BAJA;
		}
		retorno = 0;
	}
	return retorno;
}

int eProducto_Modificacion(eProducto arrayProductos[], int length)
{
	int retorno = -1;
	int idProducto;
	int index;
	int banderaAltas;
	eProducto auxiliar;

	if (!eProducto_ImprimirProductos(arrayProductos, length))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID para modificar", 3, -1, 2001, "Error ID no es valido\n", &idProducto);

		index = eProducto_BuscarPorId(arrayProductos, length, idProducto);
		while (index == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID para modificar", 3, -1, 2001, "Error ID no valida", &idProducto);
		}
		auxiliar = eProducto_ModificarUno(arrayProductos[index]);
		if (validar_Salida_SN("Esta seguro que quiere Modificar? 'S' continuar , 'N' cancelar", "Opcion no valida\n", 3))
		{
			arrayProductos[index] = auxiliar;
		}
	}
	return retorno;
}

int eProducto_SortProducto(eProducto arrayProductos[], int length, int criterio)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int nuevoLimite;
	eProducto buffer;

	if (arrayProductos != NULL && length > 0)
	{
		nuevoLimite = length - 1;
		//CRITERIO ES 1 MENOR A MAYOR, -1 MAYOR A MENOR
		switch (criterio)
		{
		case 1:
			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayProductos[i].isEmpty == OCUPADO && arrayProductos[i + 1].isEmpty == OCUPADO)
					{
						if (arrayProductos[i].idProducto > arrayProductos[i + 1].idProducto)
						{
							flagSwap = 1;
							buffer = arrayProductos[i];
							arrayProductos[i] = arrayProductos[i + 1];
							arrayProductos[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);

			//ORDENO ALFABETICAMENTE CUANDO LOS TIPOS SEAN IGUALES
			break;
		case -1:
			do
			{
				flagSwap = 0;
				for (i = 0; i < length; i++)
				{
					if (arrayProductos[i].isEmpty == OCUPADO && arrayProductos[i + 1].isEmpty == OCUPADO)
					{
						if (arrayProductos[i].categoria > arrayProductos[i + 1].categoria)
						{
							flagSwap = 1;
							buffer = arrayProductos[i];
							arrayProductos[i] = arrayProductos[i + 1];
							arrayProductos[i + 1] = buffer;
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);

			do
			{
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++)
				{
					if (arrayProductos[i].isEmpty == OCUPADO && arrayProductos[i + 1].isEmpty == OCUPADO)
					{
						if (strncmp(arrayProductos[i].nombreDelProducto, arrayProductos[i + 1].nombreDelProducto, sizeof(arrayProductos->nombreDelProducto)) > 0)
						{
							if (arrayProductos[i].categoria == arrayProductos[i + 1].categoria)
							{

								flagSwap = 1;
								buffer = arrayProductos[i];
								arrayProductos[i] = arrayProductos[i + 1];
								arrayProductos[i + 1] = buffer;
							}
						}
					}
				}
				nuevoLimite--;
			} while (flagSwap);
			break;
		default:
			retorno = -1;
			break;
		}

	}
	return retorno;
}

void eProducto_Hardcodeo(eProducto *arrayProductos, int length)
{
	char nombreDelProducto[10][25] =
	{ "ARMAS", "EL CAMINO DE LOS REYES", "ZAPATILLAS DEPORTIVAS", "AUTO 0km no fake", "JUEGUETE NINIOS", "POLYSTATION 5", "KIT VERDURAS PARA SOPA", "2KG PAPAS", "MOUNTAIN BIKE RODADO 29",
			"PAPEL PARA IMPRIMIR A4" };
	int categorias[4] =
	{ 1, 2, 3, 4 };
	for (int i = 0; i < 5; ++i)
	{
		arrayProductos[i].idProducto = eProducto_ObtenerID();
		strncpy(arrayProductos[i].nombreDelProducto, nombreDelProducto[rand() % 10], sizeof(arrayProductos[i].nombreDelProducto));
		arrayProductos[i].stock = rand() % 1000;
		arrayProductos[i].categoria = categorias[rand() % 4];
		//arrayProductos[i].password = password;
		//arrayProductos[i].correo = correo[rand()%10];
		//arrayProductos[i].direccion = direccion[rand()%5];
		arrayProductos[i].precio = rand() % 1000;
		arrayProductos[i].isEmpty = OCUPADO;
	}

}

