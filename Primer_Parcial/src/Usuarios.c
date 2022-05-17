/**
 *  Usuario.c
 *
 *
 *
 */
static int eUsuario_ObtenerID(void);
static int eUsuario_ObtenerID(void)
{
	static int usuario_IdIncremental = 0;
	return usuario_IdIncremental++;
}

#include "Usuarios.h"
static int eUsuario_ValidarLogueo(eUsuario arrayUsuarios[], int length, char *correo, char *password, int *ID, short int *tipoIngreso);
static int eUsuario_ValidarLogueo(eUsuario arrayUsuarios[], int length, char *correo, char *password, int *ID, short int *tipoIngreso)
{
	int retorno = 0;
	int respuestaCorreo;
	int respuestaPassword;
	if (arrayUsuarios != NULL && length > 0 && correo != NULL && password != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			respuestaCorreo = strncmp(arrayUsuarios[i].correo, correo, sizeof(arrayUsuarios[i].correo));
			if (respuestaCorreo == 0)
			{
				respuestaPassword = strncmp(arrayUsuarios[i].password, password, sizeof(arrayUsuarios[i].password));
				if (respuestaPassword == 0)
				{
					*ID = arrayUsuarios[i].idUsuario;
					*tipoIngreso = arrayUsuarios[i].tipo;
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}
int eUsuario_InicioDeSesion(eUsuario arrayUsuarios[], int length, int *ID, short int *tipoIngreso)
{
	int retorno = -1;
	char auxiliarCorreo[25];
	char auxiliarPassword[10];
	int auxiliarId;
	short int auxiliarTipo;

	if (arrayUsuarios != NULL && length > 0 && ID != NULL)
	{
		if (!utn_GetEmail("Ingrese su correo: ", "Correo no valido\n", 3, sizeof(auxiliarCorreo), auxiliarCorreo))
		{
			if (!utn_GetPassword("Ingrese su contrasenia: ", "La contrasenia no es Valida\n", 3, 3, sizeof(auxiliarPassword), auxiliarPassword))
			{
				if (eUsuario_ValidarLogueo(arrayUsuarios, length, auxiliarCorreo, auxiliarPassword, &auxiliarId, &auxiliarTipo))
				{
					retorno = 0;
					*ID = auxiliarId;
					*tipoIngreso = auxiliarTipo;

				}
			}
		}
	}

	return retorno;
}
void eUsuario_inicializarUsuarios(eUsuario arrayDeUsuario[], int length)
{
	int i;

	if (arrayDeUsuario != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			arrayDeUsuario[i].isEmpty = LIBRE;
		}
	}
}

int eUsuario_ObtenerIndexLibre(eUsuario arrayUsuarios[], int length)
{
	int retorno = -1;
	int i;

	if (arrayUsuarios != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayUsuarios[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eUsuario_BuscarUsuarioPorId(eUsuario arrayUsuarios[], int length, int ID)
{
	int retorno = -1;
	int i;

	if (arrayUsuarios != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayUsuarios[i].idUsuario == ID && arrayUsuarios[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eUsuario_ImprimirUsuario(eUsuario Usuario)
{
	char auxiliarEstado[10];

	printf("%4d\t%-25s", Usuario.idUsuario, Usuario.correo);

	switch (Usuario.isEmpty)
	{
	case 1:
		strncpy(auxiliarEstado, "ACTIVO", sizeof(auxiliarEstado));
		break;
	case -1:
		strncpy(auxiliarEstado, "DE BAJA", sizeof(auxiliarEstado));
		break;
	}
	printf("\t\t%-1s\n", auxiliarEstado);
	puts("=======================================================");
}

int eUsuario_ImprimirUsuarios(eUsuario arrayUsuarios[], int length)
{
	int retorno = -1;
	int banderaMensaje = 1;
	int i;
	if (arrayUsuarios != NULL && length)
	{
		for (i = 0; i < length; i++)
		{
			if (arrayUsuarios[i].isEmpty != LIBRE)
			{
				if (banderaMensaje)
				{
					puts("\n------------------Lista de Usuarios--------------------");
					printf("%5s%9s\t%38s\n", "ID", "CORREO", "ESTADO");
					puts("=======================================================");
					banderaMensaje = 0;
				}
				eUsuario_ImprimirUsuario(arrayUsuarios[i]);
				retorno = 0;
			}
		}

	}
	return retorno;
}

int eUsuario_CargarDatos(eUsuario *Usuario)
{
	int retorno = -1;
	eUsuario auxiliar;
	if (Usuario != NULL)
	{
		puts("\n-----------------Ingrese sus Datos--------------------");
		if (!utn_GetEmail("Ingrese el correo electronico: ", "Mail no valido\n", 3, 25, auxiliar.correo))
		{
			if (!utn_GetPassword("Ingrese su contrasenia: ", "contrasenia no valida, Ingrese sin signos\n", 3, 3, 10, auxiliar.password))
			{
				if (!utn_GetAlfaNumerico("Ingrese su direccion particular: ", "Direccion no valida\n", 3, 50, auxiliar.direccion))
				{
					if (!utn_GetNumero("Ingrese su codigo postal: ", 3, 0, 10000, "El codigo postal no es valido\n", &auxiliar.codPostal))
					{
						*Usuario = auxiliar;
						retorno = 0;
					}
				}
			}
		}

	}
	return retorno;
}

int eUsuario_Alta(eUsuario arrayUsuarios[], int length)
{
	int retorno = -1;
	int indexLibre;
	eUsuario auxiliarUsuario;

	indexLibre = eUsuario_ObtenerIndexLibre(arrayUsuarios, length);
	if (arrayUsuarios != NULL && length > 0)
	{
		if (indexLibre > -1)
		{
			//CARGO DATOS NO GENERICOS
			if (!eUsuario_CargarDatos(&auxiliarUsuario))
			{
				auxiliarUsuario.idUsuario = eUsuario_ObtenerID();
				auxiliarUsuario.tipo = USUARIO;
				auxiliarUsuario.isEmpty = OCUPADO;

				arrayUsuarios[indexLibre] = auxiliarUsuario;
				retorno = 0;
			}
		}
	}
	return retorno;
}


int eUsuario_DarDeBaja(eUsuario arrayUsuarios[], int length)
{
	int retorno = -1;
	int idUsuario;
	int index;
	int banderaAltas;

	if (!eUsuario_ImprimirUsuarios(arrayUsuarios, length))
	{
		banderaAltas = 1;
	}
	if (banderaAltas)
	{
		utn_GetNumero("Ingrese el ID del Usuario que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idUsuario);

		index = eUsuario_BuscarUsuarioPorId(arrayUsuarios, length, idUsuario);
		while (index == -1)
		{
			puts("NO EXISTE ID.");
			utn_GetNumero("Ingrese el ID del Usuario que quiera dar de baja: ", 3, -1, 2001, "Error ID no valida\n", &idUsuario);
			index = eUsuario_BuscarUsuarioPorId(arrayUsuarios, length, idUsuario);
		}
		if (validar_Salida_SN("Esta seguro que quiere dar de BAJA? 'S' continuar , 'N' cancelar: ", "Opcion no valida\n", 3))
		{
			arrayUsuarios[index].isEmpty = BAJA;
		}
		puts("=======================================================");
			retorno = 0;
	}
	return retorno;
}


void eUsuario_Hardcodeo(eUsuario *arrayUsuarios, int length)
{
	char correo[10][25] =
	{ "DANTEXSALDIVAR@GMAIL.COM", "MATIAS@GMAIL.COM", "RAND@GMAIL.COM", "JOSE@GMAIL.COM", "JUANCARLOS@GMAIL.COM", "PIBE_XENEIZE@GMAIL.COM", "MIGENIOAMOR@GMAIL.COM", "FANDEWANDA@GMAIL.COM",
			"XXPERROSXX@GMAIL.COM", "ROBERTOGOMEZ@GMAIL.COM" };
	char password[10] =
	{ "1234" };
	char direccion[5][25] =
	{ "CALLE FALSA 123", "EL RANCHO 342", "NO SE ME OCURRE 034", "ALMAFUERTE 943", "LA RURAL 1828" };
	int codigoPostal[10] =
	{ 1, 1828, 2033, 5304, 9853, 6430, 8356, 4030, 7309, 6304 };

	for (int i = 1; i < 6; ++i)
	{
		arrayUsuarios[i].idUsuario = eUsuario_ObtenerID();
		strncpy(arrayUsuarios[i].correo, correo[rand() % 10], sizeof(arrayUsuarios[i].correo));
		strncpy(arrayUsuarios[i].password, password, sizeof(arrayUsuarios[i].password));
		strncpy(arrayUsuarios[i].direccion, direccion[rand() % 5], sizeof(arrayUsuarios[i].direccion));
		arrayUsuarios[i].codPostal = codigoPostal[rand() % 10];
		arrayUsuarios[i].isEmpty = OCUPADO;
		arrayUsuarios[i].tipo = USUARIO;
	}
	arrayUsuarios[0].idUsuario = 16;
	strncpy(arrayUsuarios[0].correo, "ADMIN", sizeof(arrayUsuarios[0].correo));
	strncpy(arrayUsuarios[0].password, "0000", sizeof(arrayUsuarios[0].password));
	strncpy(arrayUsuarios[0].direccion, "El lobby 1929", sizeof(arrayUsuarios[0].direccion));
	arrayUsuarios[0].codPostal = 01;
	arrayUsuarios[0].isEmpty = OCUPADO;
	arrayUsuarios[0].tipo = ADMIN;

}

