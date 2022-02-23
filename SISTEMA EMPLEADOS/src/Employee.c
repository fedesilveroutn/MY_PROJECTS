#include "Employee.h"


/*--------------------------------SETTERS--------------------------------*/

/**
 * @fn int employee_setId(Employee*, int)
 * @brief inicializa el field ID con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param id int
 * @return retorna -1 si hubo error o 0 si el field ID pudo ser seteado
 */
int employee_setId(Employee* employee , int id)
{
	int ret = -1;

	if(employee != NULL && id > 0)
	{
		employee->id = id;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_setAge(Employee*, int)
 * @brief incializa el field AGE con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param age int
 * @return retorna -1 si hubo error o 0 si el field AGE pudo ser seteado
 */
int employee_setAge(Employee* employee , int age)
{
	int ret = -1;

	if(employee != NULL && age > 0)
	{
		employee->age = age;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_setSalary(Employee*, int)
 * @brief inicializa el field SALARY con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param salary int
 * @return retorna -1 si hubo error o 0 si el field SALARY pudo ser seteado
 */
int employee_setSalary(Employee* employee , float salary)
{
	int ret = -1;

	if(employee != NULL && salary > 0)
	{
		employee->salary = salary;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_setName(Employee*, char*)
 * @brief incializa el field NAME con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param name char*
 * @return retorna -1 si hubo error o 0 si el field NAME pudo ser seteado
 */
int employee_setName(Employee* employee , char* name)
{
	int ret = -1;

	if(employee != NULL && name != NULL)
	{
		strcpy (employee->name , name);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_setLastName(Employee*, char*)
 * @brief inicializa el field LASTNAME con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param lastName char*
 * @return retorna -1 si hubo error o 0 si el field LASTNAME pudo ser seteado
 */
int employee_setLastName(Employee* employee , char* lastName)
{
	int ret = -1;

	if(employee != NULL && lastName != NULL)
	{
		strcpy (employee->lastName , lastName);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_setSector(Employee*, char*)
 * @brief inicializa el field SECTOR con el valor pasado por parametro
 *
 * @param employee Employee*
 * @param sector char*
 * @return retorna -1 si hubo error o 0 si el field SECTOR pudo ser seteado
 */
int employee_setSector(Employee* employee , char* sector)
{
	int ret = -1;

	if(employee != NULL && sector != NULL)
	{
		strcpy (employee->sector , sector);
		ret = 0;
	}

	return ret;
}


/*--------------------------------GETTERS--------------------------------*/

/**
 * @fn int employee_getId(Employee*)
 * @brief obtiene el field ID de un puntero a Employee
 *
 * @param employee Employee*
 * @return retorna -1 si hubo error o el ID si funciono
 */
int employee_getId(Employee* employee)
{
	int ret = -1;

	if(employee != NULL)
	{
		ret = employee->id;
	}

	return ret;
}
/**
 * @fn int employee_getAge(Employee*)
 * @brief obtiene el field AGE de un puntero a Employee
 *
 * @param employee Employee*
 * @return retorna -1 si hubo error o el AGE si funciono
 */
int employee_getAge(Employee* employee)
{
	int ret = -1;

	if(employee != NULL)
	{
		ret = employee->age;
	}

	return ret;
}
/**
 * @fn int employee_getSalary(Employee*)
 * @brief obtiene el field SALARY de un puntero a Employee
 *
 * @param employee Employee*
 * @return retorna -1 si hubo error o el SALARY si funciono
 */
float employee_getSalary(Employee* employee)
{
	float ret = -1;

	if(employee != NULL)
	{
		ret = employee->salary;
	}

	return ret;
}
/**
 * @fn int employee_getName(Employee*, char*)
 * @brief obtiene el field NAME de un puntero a Employee
 *
 * @param employee Employee*
 * @param name char*
 * @return retorna -1 si hubo error o 0 si funciono
 */
int employee_getName(Employee* employee, char* name)
{
	int ret = -1;

	if(employee != NULL)
	{
		strcpy(name , employee->name);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_getLastName(Employee*, char*)
 * @brief obtiene el field LASTNAME de un puntero a Employee
 *
 * @param employee Employee*
 * @param lastName char*
 * @return retorna -1 si hubo error o 0 si funciono
 */
int employee_getLastName(Employee* employee, char* lastName)
{
	int ret = -1;

	if(employee != NULL)
	{
		strcpy(lastName, employee->lastName);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_getSector(Employee*, char*)
 * @brief obtiene el field SECTOR de un puntero a Employee
 *
 * @param employee Employee*
 * @param sector char*
 * @return retorna -1 si hubo error o 0 si funciono
 */
int employee_getSector(Employee* employee, char* sector)
{
	int ret = -1;

	if(employee != NULL)
	{
		strcpy(sector, employee->sector);
		ret = 0;
	}

	return ret;
}


/*--------------------------------CONSTRUCTORS--------------------------------*/

/**
 * @fn Employee employee_new*()
 * @brief reserva un espacio en memoria dinamica para una estructura Employee
 *
 * @return retorna NULL si hubo error o un puntero a la direccion de memoria de la estructura
 */
Employee* employee_new()

{
	Employee* new = (Employee*) malloc (sizeof(Employee));
	return new;
}
/**
 * @fn Employee employee_newParam*(int, int, char*, char*, char*)
 * @brief reserva un espacio en memoria dinamica para una estructura Employee* e inicializa todos sus fields
 *
 * @param id int
 * @param age int
 * @param name char*
 * @param lastName char*
 * @param sector char*
 * @return retorna NULL si hubo error o el puntero a Employee con sus fields cargados si funciono correctamente
 */
Employee* employee_newParam(int id, int age, float salary, char* name, char* lastName,char* sector)
{
	Employee* new = NULL;
	if(id > -1 && age > -1 && salary > 0 && name != NULL && lastName != NULL && sector != NULL)
	{
		new = employee_new();
		if(new != NULL)
		{
			employee_setId(new, id);
			employee_setAge(new, age);
			employee_setSalary(new, salary);
			employee_setName(new, name);
			employee_setLastName(new, lastName);
			employee_setSector(new, sector);
		}
	}

	return new;
}

/*--------------------------------LIST--------------------------------*/

/**
 * @fn void employee_header(void)
 * @brief muestra el encabezado con los datos de un empleado
 *
 */
void employee_header(void)
{
	printf(	"\n------------------------------------------------------------------------------------------------------------------------------------"
			"\n%-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "EDAD", "SECTOR", "SUELDO"
			"\n------------------------------------------------------------------------------------------------------------------------------------");
}
/**
 * @fn int employee_list(Employee*)
 * @brief lista un empleado
 *
 * @param employee Employee*
 * @return retorna -1 si hubo error o 0 si pudo listar el empleado
 */
int employee_printEmployee(Employee* employee)
{
	int ret = -1;
	int id;
	int age;
	float salary;
	char name[128];
	char lastName[128];
	char sector[128];

	if(employee != NULL)
	{
		id = employee_getId(employee);
		age = employee_getAge(employee);
		salary = employee_getSalary(employee);
		employee_getName(employee, name);
		employee_getLastName(employee, lastName);
		employee_getSector(employee, sector);

		printf("\n%-20d %-20s %-20s %-20d %-20s %-20.2f", id, name, lastName, age, sector, salary);
		ret = 0;
	}

	return ret;
}
/**
 * @fn int employee_printList(LinkedList*)
 * @brief imprime una linkedlist de empleados
 *
 * @param this LinkedList*
 * @return retorna -1 si hubo error o 0 si la lista pudo ser mostrada
 */
int employee_printList(LinkedList* this)
{
	Employee* aux = NULL;
	int ret = -1;
	int len;
	int i;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		employee_header();

		for(i = 0; i < len; i++)
		{
			aux = (Employee*)linkedlist_get(this, i);
			employee_printEmployee(aux);
		}

		printf(	"\n------------------------------------------------------------------------------------------------------------------------------------");
		ret = 0;
	}

	return ret;
}

/*--------------------------------CREATE--------------------------------*/

/**
 * @fn Employee employee_ask*(int)
 * @brief solicita el ingreso de los datos necesarios para agregar un empleado
 *
 * @param id int
 * @return retorna NULL si hubo error o un puntero a un empleado con sus campos cargados
 */
Employee* employee_ask(int id)
{
	Employee* new = NULL;
	int age;
	float salary;
	char name[128];
	char lastName[128];
	char sector[128];

	getString(name, "\nINGRESE EL NOMBRE: ", "\nERROR. REINGRESE UN NOMBRE VALIDO (127 caracteres): ", 128);
	getString(lastName, "INGRESE EL APELLIDO: ", "\nERROR. REINGRESE UN APELLIDO VALIDO (127 caracteres): ", 128);
	getInt(&age, "INGRESE LA EDAD: ", "\nERROR. REINGRESE UNA EDAD VALIDA (18-70): ", 18 , 70);
	getFloat(&salary, "INGRESE EL SUELDO: ","\nERROR. REINGRESE UN SUELDO VALIDO (10.000 - 500.000): ", 10000, 500000);
	getString(sector, "INGRESE EL SECTOR: ", "\nERROR. REINGRESE UN SECTOR VALIDO (127 caracteres): ", 128);

	stringFormat(name, 0);
	stringFormat(lastName, 0);
	stringFormat(sector, 0);

	new = employee_newParam(id, age, salary, name, lastName, sector);
	return new;
}
/**
 * @fn int employee_confirm(Employee*, char*, char*)
 * @brief solicita que el usuario confirme los datos ingresados
 *
 * @param employee Employee*
 * @param message char*
 * @param error char*
 * @return retorna -1 si hubo error 0 si la respuesta es si o 1 si la respuesta es no
 */
int employee_confirm(Employee* employee, char* message, char* error)
{
	int ret = -1;
	int resultYes;
	int resultNo;
	int follow;
	int len;
	char answer[5];

	if(employee != NULL)
	{
		do
		{
			employee_header();
			employee_printEmployee(employee);

			getString(answer, message, error, 4);
			len = strlen(answer);
			stringFormat(answer, -1);

			resultYes = strcmp(answer, "si");
			resultNo = strcmp(answer, "no");
			if(resultYes != 0 && resultNo != 0)
			{
				follow = -1;
				printf("\nRESPUESTA INVALIDA.");
				systemPause("\nLEA ATENTAMENTE LA INFORMACION Y RESPONDA CON (SI O NO). PRESIONE ENTER PARA CONTINUAR...");
			}

			else
			{
				follow = 0;
			}

		}while(follow == -1);

		if(resultYes == 0)
		{
			ret = 0;
		}

		else if(resultNo == 0)
		{
			ret = 1;
		}
	}

	return ret;
}
/**
 * @fn int employee_add(LinkedList*, int)
 * @brief agrega un empleado con sus campos cargados
 *
 * @param this LinkedList*
 * @param id int
 * @return retorna -1 si hubo error o 0 si funciono
 */
int employee_add(LinkedList* this, int id)
{
	Employee* new = NULL;
	int ret = -1;
	int answer;

	new = employee_ask(id);
	if(this != NULL && new != NULL)
	{
		answer = employee_confirm(new, 	"\n------------------------------------------------------------------------------------------------------------------------------------"
										"\nCONFIRMA QUE LOS DATOS SON CORRECTOS? (si / no) : ",
										"\nERROR. REINGRESE UNA RESPUESTA VALIDA (si / no): ");
		if(answer == 0)
		{
			ret = linkedlist_add(this, new);
			if(!ret)
			{
				positiveMessage("EMPLEADO AGREGADO EXITOSAMENTE!");
			}
			else
			{
				negativeMessage("ERROR. NO SE HA PODIDO AGREGAR EL EMPLEADO!");
			}
		}

		else
		{
			negativeMessage("CARGA DE EMPLEADO CANCELADA!");
		}
	}

	return ret;
}
/**
 * @fn int employee_delete(LinkedList*)
 * @brief elimina un empleado de la linkedlist
 *
 * @param this LinkedLIst*
 * @return retorna -1 si hubo error o 0 si el empleado pudo ser eliminado
 */
int employee_delete(LinkedList* this)
{
	Employee* auxEmployee = NULL;
	int ret = -1;
	int auxId;
	int len;
	int id;
	int i;
	int answer;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		employee_printList(this);
		getInt(&id, "\nINGRESE EL ID DEL EMPLEADO QUE DESEA ELIMINAR: ", "\nERROR. REINGRESE UN ID VALIDO (1000-9999): ", 1000, 9999);

		for(i = 0; i < len; i++)
		{
			auxEmployee = linkedlist_get(this, i);
			auxId = employee_getId(auxEmployee);
			if(id == auxId)
			{
				printf("\n\n\n\n\n");
				answer = employee_confirm(auxEmployee, "\n------------------------------------------------------------------------------------------------------------------------------------"
													   "\nELIMINAR AL EMPLEADO SELECCIONADO? (si / no): ",
													   "\nERROR. REINGRESE UNA RESPUESTA VALIDA (si / no): ");
				if(!answer)
				{
					ret = linkedlist_remove(this, i);
					if(!ret)
					{
						positiveMessage("EMPLEADO ELIMINADO EXITOSAMENTE!");
					}
					else
					{
						negativeMessage("ERROR. NO SE HA PODIDO ELMINAR EL EMPLEADO!");
					}
				}

				else
				{
					negativeMessage("HA CANCELADO LA ELIMINACION DEL EMPLEADO!");
				}

				break;
			}
		}
	}

	return ret;
}

/*--------------------------------CHANGE--------------------------------*/

/**
 * @fn int employee_edit(LinkedList*)
 * @brief edita la propiedad indicada de un empleado
 *
 * @param this LinkedList*
 * @return retorna -1 si hubo error o 0 si la propiedad pudo ser modificada correctamente
 */
int employee_edit(LinkedList* this)
{
	Employee* employee = NULL;
	Employee* auxEmployee = NULL;
	char auxLastName[128];
	char auxSector[128];
	char auxName[128];
	int auxAge;
	float auxSalary;
	int auxId;
	int ret = -1;
	int option;
	int len;
	int id;
	int i;
	int answer;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		employee_printList(this);
		getInt(&id, "\nINGRESE EL ID DEL EMPLEADO QUE DESEA MODIFICAR: ", "\nERROR. REINGRESE UN ID VALIDO (1000-9999): ", 1000, 9999);
		for(i = 0; i < len; i++)
		{
			employee = linkedlist_get(this, i);
			auxId = employee_getId(employee);
			if(id == auxId)
			{
				getInt(&option, "\n-----------------------------------------------------------------"
								"\n1. NOMBRE"
								"\n2. APELLIDO"
								"\n3. EDAD"
								"\n4. SUELDO"
								"\n5. SECTOR"
								"\n-----------------------------------------------------------------"
								"\nSELECCIONE LA PROPIEDAD A MODIFICAR: ", "\nERROR. REINGRESE UNA OPCION VALIDA (1-5): ", 1 , 5);

				auxEmployee = employee_newParam(employee->id, employee->age, employee->salary, employee->name, employee->lastName,  employee->sector);
				switch(option)
				{
					case 1:
							getString(auxName, "\nINGRESE EL NUEVO NOMBRE: ", "\nERROR. REINGRESE UN NOMBRE VALIDO (hasta 127 caracteres): ", 128);
							stringFormat(auxName, 0);
							employee_setName(auxEmployee, auxName);
							break;
					case 2:
							getString(auxLastName, "\nINGRESE EL NUEVO APELLIDO: ", "\nERROR. REINGRESE UN APELLIDO VALIDO (hasta 127 caracteres): ", 128);
							stringFormat(auxLastName, 0);
							employee_setLastName(auxEmployee, auxLastName);
							break;
					case 3:
							getInt(&auxAge, "\nINGRESE LA NUEVA EDAD: ", "\nERROR. REINGRESE UNA EDAD VALIDA (18-70): ", 18 , 70);
							employee_setAge(auxEmployee, auxAge);
							break;
					case 4:
							getFloat(&auxSalary, "\nINGRESE EL NUEVO SUELDO: ", "\nERROR. REINGRESE UN SUELDO VALIDO (10.000-500.000): ", 10000 , 500000);
							employee_setSalary(auxEmployee, auxSalary);
							break;
					case 5:
							getString(auxSector, "\nINGRESE EL NUEVO SECTOR: ", "\nERROR. REINGRESE UN SECTOR VALIDO (hasta 127 caracteres): ", 128);
							stringFormat(auxSector, 0);
							employee_setSector(auxEmployee, auxSector);
							break;
				}
				answer = employee_confirm(auxEmployee, "\n------------------------------------------------------------------------------------------------------------------------------------"
													   "\nDESEA CONFIRMAR LA MODIFICACION? (si / no): ",
													   "\nERROR. REINGRESE UNA RESPUESTA VALIDA (si / no): ");
				if(answer == 0)
				{
					employee = auxEmployee;
					ret = linkedlist_set(this, i, employee);
					if(!ret)
					{
						positiveMessage("EMPLEADO MODIFICADO EXITOSAMENTE!");
					}
					else
					{
						negativeMessage("ERROR. NO SE HA PODIDO MODIFICAR EL EMPLEADO!");
					}
				}
				else if (answer == 1)
				{
					negativeMessage("HA CANCELADO LA MODIFICACION DEL EMPLEADO!");
				}
			}
		}
	}
	return ret;
}
/**
 * @fn int employee_sortById(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortById(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	int id1;
	int id2;
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		id1 = employee_getId(employee1);
		id2 = employee_getId(employee2);

		if (id1 < id2)
		{
			ret = -1;
		}

		else if (id1 > id2)
		{
			ret = 1;
		}

		else if (id1 == id2)
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sortByName(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortByName(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	char name1 [128];
	char name2 [128];
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getName(employee1, name1);
		employee_getName(employee2, name2);
		ret = strcmp(name1, name2);

		if(ret < 0)
		{
			ret = -1;
		}
		else if(ret > 0)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sortByLastName(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortByLastName(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	char lastName1 [128];
	char lastName2 [128];
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getLastName(employee1, lastName1);
		employee_getLastName(employee2, lastName2);
		ret = strcmp(lastName1, lastName2);

		if(ret < 0)
		{
			ret = -1;
		}
		else if(ret > 0)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sortByAge(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortByAge(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	int age1;
	int age2;
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		age1 = employee_getAge(employee1);
		age2 = employee_getAge(employee2);

		if (age1 < age2)
		{
			ret = -1;
		}

		else if (age1 > age2)
		{
			ret = 1;
		}

		else if (age1 == age2)
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sortBySalary(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortBySalary(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	float salary1;
	float salary2;
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		salary1 = employee_getSalary(employee1);
		salary2 = employee_getSalary(employee2);

		if (salary1 < salary2)
		{
			ret = -1;
		}

		else if (salary1 > salary2)
		{
			ret = 1;
		}

		else if (salary1 == salary2)
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sortBySector(void*, void*)
 * @brief
 *
 * @param pointer1
 * @param pointer2
 * @return
 */
int employee_sortBySector(void* pointer1 , void* pointer2)
{
	Employee* employee1 = (Employee*)pointer1;
	Employee* employee2 = (Employee*)pointer2;
	char sector1 [128];
	char sector2 [128];
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getSector(employee1, sector1);
		employee_getLastName(employee2, sector2);
		ret = strcmp(sector1, sector2);

		if(ret < 0)
		{
			ret = -1;
		}
		else if(ret > 0)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @fn int employee_sort(LinkedList*)
 * @brief
 *
 * @param this
 * @return
 */
int employee_sort(LinkedList* this)
{
	int option;
	int order;
	int ret = -1;
	int (*toSortById)(void*, void*);
	int (*toSortByName)(void*, void*);
	int (*toSortByLastName)(void*, void*);
	int (*toSortByAge)(void*, void*);
	int (*toSortBySalary)(void*, void*);
	int (*toSortBySector)(void*, void*);

	toSortById = employee_sortById;
	toSortByName = employee_sortByName;
	toSortByLastName = employee_sortByLastName;
	toSortByAge = employee_sortByAge;
	toSortBySalary = employee_sortBySalary;
	toSortBySector = employee_sortBySector;

	getInt(&option , "\n------------------------SUBMENU-------------------------\n"
					 "\n1. Ordenar segun el ID"
					 "\n2. Ordenar segun el NOMBRE"
					 "\n3. Ordenar segun el APELLIDO"
					 "\n4. Ordenar segun la EDAD"
					 "\n5. Ordenar segun el SUELDO"
					 "\n6. Ordenar segun el SECTOR"
					 "\n--------------------------------------------------------\n"
					 "\nIngrese una opcion (1-6): ", "\nReingrese una opcion valida (1-6): ", 1 , 6	);

	getInt(&order,"De que manera desea ordenar la lista? (1 = CRECIENTE | 0 = DECRECIENTE): ",
				  "\nERROR. INGRESAR UN NUMERO VALIDO (1 = CRECIENTE | 0 = DECRECIENTE): ", 0, 1);

	switch (option)
	{
		case 1:
				ret = linkedlist_sort(this, toSortById, order);
				break;
		case 2:
				ret = linkedlist_sort(this, toSortByName, order);
				break;

		case 3:
				ret = linkedlist_sort(this, toSortByLastName, order);
				break;
		case 4:
				ret = linkedlist_sort(this , toSortByAge , order);
				break;
		case 5:
				ret = linkedlist_sort(this , toSortBySalary , order);
				break;
		case 6:
				ret = linkedlist_sort(this , toSortBySector , order);
				break;
	}

	if(!ret)
	{
		positiveMessage("LISTA ORDENADA EXITOSAMENTE!");
	}
	else
	{
		negativeMessage("ERROR. NO SE HA PODIDO ORDENAR LA LISTA!");
	}

	return ret;
}



int employee_averageSalary(LinkedList* this)
{
	Employee* employee = NULL;
	float salaryAcum = 0;
	float averageSalary;
	int count = 0;
	int ret = -1;
	int len;
	int i;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		for (i = 0; i < len; i++)
		{
			employee = (Employee*)linkedlist_get(this, i);
			salaryAcum += employee_getSalary(employee);
			count++;
		}

		averageSalary = calculator_averageSalary(salaryAcum, count);
		printf("\nEL SUELDO PROMEDIO ES: %.2f", averageSalary);
		ret = 0;
	}

	return ret;
}
