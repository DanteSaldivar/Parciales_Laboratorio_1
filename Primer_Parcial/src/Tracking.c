/**
 *  Tracking.c
 *
 *
 *
 */

#include "Tracking.h"

void eTracking_InicializarTrackings(eTracking arrayDeTracking[], int length)
{
	int i;

	if (arrayDeTracking != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			arrayDeTracking[i].isEmpty = LIBRE;
		}
	}
}

int eTracking_ObtenerIndexLibre(eTracking arrayTrackings[], int length)
{
	int retorno = -1;
	int i;

	if (arrayTrackings != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayTrackings[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eTracking_BuscarPorId(eTracking arrayTrackings[], int length, int ID)
{
	int retorno = -1;
	int i;

	if (arrayTrackings != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayTrackings[i].idTracking == ID && arrayTrackings[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eTracking_ImprimirTracking(eTracking Tracking)
{
	char auxiliarEstado[25];

	printf("%d\t%d\t\t15%d", Tracking.idTracking, Tracking.Fk_comprador, Tracking.Fk_vendedor);

	if (Tracking.horaLlegada != -1)
	{
		if (Tracking.horaLlegada > timeCurrent())
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
	printf("\t%18s\n", auxiliarEstado);
	puts("=====================================================");
}

int eTracking_ImprimirTrackings(eTracking arrayTrackings[], int length)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;

	if (arrayTrackings != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayTrackings[i].isEmpty != LIBRE)
			{
				if (banderaMensaje)
				{
					puts("\n----------------Lista GLOBAL DE VENTAS --------------");
					printf("%2s\t%5s\t%s\t%8s\n", "ID", "ID COMPRADOR", "ID VENDEDOR", "ESTADO");
					puts("=====================================================");
					banderaMensaje = 0;
				}
				eTracking_ImprimirTracking(arrayTrackings[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}


int eTracking_CancelarTracking(eTracking arrayTrackings[], int length, int ID)
{
	int retorno = -1;
	int idTracking;
	int index;

	utn_GetNumero("Ingrese el ID del Tracking que quiera cancelar : ", 3, -1, 2001, "Error ID no valida\n", &idTracking);

	index = eTracking_BuscarPorId(arrayTrackings, length, idTracking);
	while (index == -1 || arrayTrackings[index].Fk_comprador != ID)
	{
		puts("NO EXISTE ID.");
		utn_GetNumero("Ingrese el ID del Tracking que quiera cancelar : ", 3, -1, 2001, "Error ID no valida\n", &idTracking);
		index = eTracking_BuscarPorId(arrayTrackings, length, idTracking);
	}
	if (arrayTrackings[index].horaLlegada > timeCurrent())
	{
		if (validar_Salida_SN("Esta seguro que quiere CANCELAR el Pedido? 'S' continuar , 'N' cancelar", "Opcion no valida\n", 3))
		{
			arrayTrackings[index].isEmpty = BAJA;
			arrayTrackings[index].horaLlegada = -1;
			retorno = 0;
		}
	}
	return retorno;
}




