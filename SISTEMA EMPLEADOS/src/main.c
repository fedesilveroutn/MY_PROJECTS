/*
 ============================================================================
 Name        : SISTEMA.c
 Author      : Federico Elias Silvero
 Version     : 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Employee.h"
#include "Calculator.h"
#include "LinkedList.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* list = linkedlist_new();
	int employeeCount = 0;
	int lastId = 999;
	int flag = 0;
	int option;
	int ret;

	do
	{
		menu();
		getInt(&option, "\nINGRESE UNA OPCION: ", "ERROR. REINGRESE UNA OPCION VALIDA (1-7): ", 1 , 7);
		switch(option)
		{
		case 1:
				actionMessage("Agregando un empleado...");
				ret = employee_add(list, lastId + 1);
				if(!ret)
				{
					flag = 1;
					lastId++;
					employeeCount++;
				}
				systemPause("Presione ENTER para continuar...\n\n\n");
				break;

		case 2:
				if(flag)
				{
					printf("\nModificando un empleado...");
					employee_edit(list);
				}

				else
				{
					negativeMessage("ERROR. ACCESO DENEGADO. DEBE DAR DE ALTA POR LO MENOS A UN EMPLEADO PARA MODIFICARLO!");
				}
				systemPause("Presione ENTER para continuar...\n\n\n");
				break;

		case 3:
				if(flag && employeeCount > 0)
				{
					printf("\n\n\n\n\nEliminando un empleado...");
					ret = employee_delete(list);
					if(!ret)
					{
						employeeCount--;
					}
				}

				else
				{
					negativeMessage("ERROR. ACCESO DENEGADO. DEBE DAR DE ALTA POR LO MENOS A UN EMPLEADO PARA ELIMINARLO!");
				}
				systemPause("Presione ENTER para continuar...\n\n\n");
				break;

		case 4:
				if(flag && employeeCount > 1)
				{
					employee_sort(list);
				}

				else
				{
					negativeMessage("ERROR. ACCESO DENEGADO. DEBE DAR DE ALTA POR LO MENOS A UN EMPLEADO PARA ORDENARLO!");;
				}
				systemPause("\nPresione ENTER para continuar...\n\n\n");
				break;

		case 5:
				if(flag && employeeCount > 0)
				{
					printf("\n\n\n\n\nMostrando la lista completa...");
					employee_printList(list);
				}

				else
				{
					negativeMessage("ERROR. ACCESO DENEGADO. DEBE DAR DE ALTA POR LO MENOS A UN EMPLEADO PARA MOSTRARLO!");;
				}
				systemPause("\nPresione ENTER para continuar...\n\n\n");
				break;

		case 6:
				if(flag && employeeCount > 0)
				{
					employee_averageSalary(list);
					systemPause("\nPresione ENTER para continuar...\n\n\n");
				}
				else
				{
					negativeMessage("ERROR. ACCESO DENEGADO. DEBE DAR DE ALTA POR LO MENOS A UN EMPLEADO PARA MOSTRARLO!");;
				}
				break;

		}

	}while(option != 7);

	printf("\nFIN DEL PROGRAMA.");
	return 0;
}









