/***
 * Relaciones.c
 *
 *
 *
 */
static int eRelaciones_Tracking_ObtenerID(void);
static int eRelaciones_Tracking_ObtenerID(void)
{
	static int Tracking_IdIncremental = 0;
	return Tracking_IdIncremental++;
}
#include "Relaciones.h"

int eRelaciones_AltaCompra(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int idUsuario)
{
	int retorno = -1;
	int banderaProductos = 0;
	int indexLibre;
	int idProducto;
	int indexProducto;
	int auxiliarStock;
	float totalPagar;

	//char aux[50];

	if (arrayProductos != NULL && arrayTracking != NULL && arrayUsuarios != NULL && usuariosLen > 0 && productosLen > 0 && trackingLen > 0)
	{
		if (!eProducto_ImprimirProductos(arrayProductos, productosLen))
		{
			banderaProductos = 1;
		}

		if (banderaProductos)
		{
			utn_GetNumero("Ingrese el ID del producto que quiera comprar: ", 3, -1, 2001, "Error ID no es valido\n", &idProducto);

			indexProducto = eProducto_BuscarPorId(arrayProductos, productosLen, idProducto);
			while (indexProducto == -1)
			{
				puts("NO EXISTE ID.");
				utn_GetNumero("Ingrese el ID del producto que quiera comprar: ", 3, -1, 2001, "Error ID no es valido\n", &idProducto);
			}

			if (arrayProductos[indexProducto].stock > 0)
			{
				if (!utn_GetNumero("Ingrese la cantidad de unidades: ", 2, 0, arrayProductos[indexProducto].stock + 1, "La cantidad no es valida", &auxiliarStock))
				{
					indexLibre = eTracking_ObtenerIndexLibre(arrayTracking, trackingLen);
					if (indexLibre > -1)
					{
						arrayTracking[indexLibre].Fk_comprador = idUsuario;
						arrayTracking[indexLibre].idProducto = idProducto;
						arrayTracking[indexLibre].Fk_vendedor = arrayProductos[indexProducto].Fk_vendedor;
						arrayTracking[indexLibre].cantidad = auxiliarStock;
						arrayTracking[indexLibre].idTracking = eRelaciones_Tracking_ObtenerID();
						arrayTracking[indexLibre].distanciaKM = calcularDistancia(arrayUsuarios[idUsuario].codPostal);
						arrayTracking[indexLibre].horaLlegada = time_Add(Multiplicar(arrayTracking[indexLibre].distanciaKM, 2));

						totalPagar = Multiplicar(arrayProductos[indexProducto].precio, auxiliarStock);
						printf("\nEl Total a pagar es: $%.2f\n", totalPagar);
						if (validar_Salida_SN("Esta seguro que quiere realizar la compra? 'S' continuar , 'N' cancelar: \n", "Opcion no valida\n", 3))
						{
							arrayProductos[indexProducto].stock = Restar(arrayProductos[indexProducto].stock, auxiliarStock);
							arrayTracking[indexLibre].isEmpty = OCUPADO;
						}
					}
				}
			}
		}
	}
	puts("-----------------------------------------------------");
	return retorno;
}

int eRelaciones_MostrarEstadoCompra(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int ID)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;
	int aux;

	if (arrayUsuarios != NULL && arrayTracking != NULL && arrayProductos != NULL && usuariosLen > 0 && productosLen > 0 && trackingLen > 0)
	{

		for (i = 0; i < trackingLen; i++)
		{
			if (arrayTracking[i].isEmpty != LIBRE)
			{
				if (arrayTracking[i].Fk_comprador == ID)
				{

					if (banderaMensaje)
					{
						puts("\n----------------------Lista compras------------------");
						printf("%2s\t%-25s\t%s\n", "ID", "PRODUCTO", "ESTADO");
						puts("=====================================================");
						banderaMensaje = 0;
					}
					eRelaciones_ImprimirTracking(arrayTracking[i], arrayProductos, productosLen);
					retorno = 0;
				}
			}
		}
		if (!utn_GetNumero("1)Cancelar un Pedido\n2)Salir : ", 3, 0, 3, "Esa opcion no esta disponible\n", &aux) && retorno == 0)
		{
			switch (aux)
			{
			case 1:
				if (eTracking_CancelarTracking(arrayTracking, trackingLen, ID) == -1)
				{
					puts("No se pudo CANCELAR la compra.");
				}
				else
				{
					puts("La compra ha sido cancelada.");
				}
				break;
			}
		}
	}
	puts("\n-----------------------------------------------------\n");

	return retorno;
}

int eRelaciones_MostrarEstadoVentas(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int ID)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;

	if (arrayUsuarios != NULL && arrayTracking != NULL && arrayProductos != NULL && usuariosLen > 0 && productosLen > 0 && trackingLen > 0)
	{

		for (i = 0; i < trackingLen; i++)
		{
			if (arrayTracking[i].isEmpty != LIBRE)
			{
				if (arrayTracking[i].Fk_vendedor == ID)
				{

					if (arrayTracking[i].horaLlegada < timeCurrent())
					{

						if (banderaMensaje)
						{
							puts("\n----------------Lista VENTAS Finalizadas---------------");
							printf("%2s\t%-25s\t%s\n", "ID", "PRODUCTO", "ESTADO");
							puts("=====================================================");
							banderaMensaje = 0;
						}
						eRelaciones_ImprimirTracking(arrayTracking[i], arrayProductos, productosLen);
						retorno = 0;
						puts("-----------------------------------------------------\n");
					}
				}
			}
		}
	}

	return retorno;
}

void eRelaciones_ImprimirTracking(eTracking arrayTracking, eProducto arrayProductos[], int productosLen)
{
	int indexProducto;
	char auxiliarEstado[25];

	indexProducto = eProducto_BuscarPorId(arrayProductos, productosLen, arrayTracking.idProducto);
	printf("%d\t%-25s", arrayTracking.idTracking, arrayProductos[indexProducto].nombreDelProducto);

	if (arrayTracking.horaLlegada != -1)
	{
		if (arrayTracking.horaLlegada > timeCurrent())
		{
			strncpy(auxiliarEstado, "EN VIAJE", sizeof(auxiliarEstado));
		}
		else
		{
			strncpy(auxiliarEstado, "ENTREGADO", sizeof(auxiliarEstado));
		}
	}
	else
	{
		strncpy(auxiliarEstado, "CANCELADO", sizeof(auxiliarEstado));
	}
	printf("\t%s\n", auxiliarEstado);
	puts("=====================================================");
}



