#include "Input.h"


/*--------------------------------INPUT DATA--------------------------------*/

/**
 * @fn int getInt(int*, char*, char*, int, int)
 * @brief pide el ingreso de un numero entero y lo valida
 *
 * @param num int*
 * @param message char*
 * @param error char*
 * @param min int
 * @param max int
 * @return retorna -1 si hubo error o 0 si el numero ingresado es valido
 */
int getInt (int* num, char* message, char* error, int min, int max)
{
	int ret = -1;
	int auxNum;
	char auxString[128];

	if(num != NULL && message != NULL && error != NULL && min < max)
	{
		printf("%s", message);
		fpurge(stdin);
		scanf("%[^\n]", auxString);
		auxNum = atoi(auxString);

		while(auxNum < min || auxNum > max)
		{
			printf("%s", error);
			fpurge(stdin);
			scanf("%[^\n]", auxString);
			auxNum = atoi(auxString);
		}

		*num = auxNum;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int getFloat(float*, char*, char*, int, int)
 * @brief pide el ingreso de un numero flotante y lo valida
 *
 * @param num float*
 * @param message char*
 * @param error char*
 * @param min float
 * @param max float
 * @return retorna -1 si hubo error o 0 si el numero ingresado es valido
 */
int getFloat (float* num, char* message, char* error, float min, float max)
{
	int ret = -1;
	float auxNum;
	char auxString[128];

	if(num != NULL && message != NULL && error != NULL && min < max)
	{
		printf("%s", message);
		fpurge(stdin);
		scanf("%[^\n]", auxString);
		auxNum = atof(auxString);

		while(auxNum < min || auxNum > max)
		{
			printf("%s", error);
			fpurge(stdin);
			scanf("%[^\n]", auxString);
			auxNum = atof(auxString);
		}

		*num = auxNum;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int getString(char*, char*, char*, int)
 * @brief pide el ingreso de una cadena de caracteres y la valida
 *
 * @param string char*
 * @param message char*
 * @param error cgar*
 * @param max int
 * @return retorna -1 si hubo error o 0 si la cadena ingresada es valida
 */
int getString (char* string, char* message, char* error, int max)
{
	int len;
	int isNum;
	int ret = -1;
	char auxString[128];

	if( string != NULL && message != NULL && error != NULL && max > 0)
	{
		printf("%s", message);
		fpurge(stdin);
		scanf("%[^\n]", auxString);
		len = strlen(auxString);
		isNum = atoi(auxString);

		while(len > max || isNum != 0)
		{
			printf("%s", error);
			fpurge(stdin);
			scanf("%[^\n]", auxString);
			len = strlen(auxString);
			isNum = atoi(auxString);
		}

		strcpy(string, auxString);
		ret = 0;

	}

	return ret;
}
/**
 * @fn int systemPause(char*)
 * @brief detiene la ejecucion del programa hasta que el usuario ingrese un caracter
 *
 * @param message char*
 * @return retorna -1 si hubo error o 0 si funciono
 */
int systemPause(char* message)
{
	int ret = -1;

	if(message != NULL)
	{
		printf("%s", message);
		fpurge(stdin);
		getchar();
		ret = 0;
	}

	return ret;
}


/*--------------------------------OUTPUT DATA--------------------------------*/

/**
 * @fn void menu()
 * @brief imprime el menu de opciones
 *
 */
void menu()
{
	printf( "\n-------------------------------MENU-------------------------------"
			"\n1. AGREGAR UN EMPLEADO"
			"\n2. MODIFICAR UN EMPLEADO"
			"\n3. ELIMINAR UN EMPLEADO"
			"\n4. ORDENAR LISTA"
			"\n5. LISTAR EMPLEADOS"
			"\n6. CALCULADORA"
			"\n7. SALIR"
			"\n------------------------------------------------------------------");
}
/**
 * @fn void positiveMessage(char*)
 * @brief imprime un mensaje encerrado entre los simbolos < >
 *
 * @param message char*
 */
void positiveMessage(char* message)
{
	printf( "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
			"\n%s\n"
			"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n", message);
}
/**
 * @fn void negativeMessage(char*)
 * @brief imprime un mensaje encerrado entre barras
 *
 * @param message char*
 */
void negativeMessage(char* message)
{

	printf( "\n//////////////////////////////////////////////////////////////////\n"
			"\n%s\n"
			"\n//////////////////////////////////////////////////////////////////\n", message);
}
/**
 * @fn void actionMessage(char*)
 * @brief imprime un mensaje encerrado entre guiones
 *
 * @param message char*
 */
void actionMessage(char* message)
{
	printf( "\n------------------------------------------------------------------"
			"\n%s"
			"\n------------------------------------------------------------------", message);
}
/**
 * @fn int stringFormat(char*, int)
 * @brief recibe una cadena de caracteres y le da el formato especificado
 *
 * @param string char*
 * @param format int
 * @return retorna -1 si hubo error o 0 si la cadena pudo ser formateada
 */
int stringFormat(char* string, int format)
{
	int ret = -1;
	int len;
	int i;

	if(string != NULL && format > -2 && format < 2 )
	{
		len = strlen(string);

		switch(format)
		{
		//Todo minuscula
		case -1:
				for(i = 0; i < len + 1; i++)
				{
					string[i] = tolower(string[i]);
				}
				break;

		//Todo mayuscula
		case 1:
				for(i = 0; i < len + 1; i++)
				{
					string[i] = toupper(string[i]);
				}
				break;

		//Primera mayuscula, el resto minuscula
		case 0:
				for(i = 0; i < len + 1; i++)
				{
					string[i] = tolower(string[i]);
				}
				string[0] = toupper(string[0]);
				break;
		}

		ret = 0;
	}

	return ret;
}




