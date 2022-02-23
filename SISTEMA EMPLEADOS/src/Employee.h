#ifndef EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "LinkedList.h"
#include "Calculator.h"
#define EMPLOYEE_H_

typedef struct
{
	int id;
	int age;
	float salary;
	char name[128];
	char lastName[128];
	char sector[128];

}Employee;

/*--------------------------------SETTERS--------------------------------*/
int employee_setId(Employee* employee , int id);
int employee_setAge(Employee* employee , int age);
int employee_setSalary(Employee* employee , float salary);
int employee_setName(Employee* employee , char* name);
int employee_setLastName(Employee* employee , char* lastName);
int employee_setSector(Employee* employee , char* sector);

/*--------------------------------GETTERS--------------------------------*/
int employee_getId(Employee* employee);
int employee_getAge(Employee* employee);
float employee_getSalary(Employee* employee);
int employee_getName(Employee* employee, char* name);
int employee_getLastName(Employee* employee, char* lastName);
int employee_getSector(Employee* employee, char* sector);

/*--------------------------------CONSTRUCTORS--------------------------------*/
Employee* employee_new();
Employee* employee_newParam(int id, int age, float salary, char* name, char* lastName,char* sector);

/*--------------------------------LIST--------------------------------*/

void employee_header(void);
int employee_printEmployee(Employee* employee);
int employee_printList(LinkedList* this);
//int employee_sort(LinkedList* this, int order);

/*--------------------------------CREATE--------------------------------*/

Employee* employee_ask(int id);
int employee_confirm(Employee* employee, char* message, char* error);
int employee_add(LinkedList* this, int id);
int employee_delete(LinkedList* this);

/*--------------------------------CHANGE--------------------------------*/
int employee_edit(LinkedList* this);
int employee_sortById(void* pointer1 , void* pointer2);
int employee_sortByName(void* pointer1 , void* pointer2);
int employee_sortByLastName(void* pointer1 , void* pointer2);
int employee_sortBySalary(void* pointer1 , void* pointer2);
int employee_sortByAge(void* pointer1 , void* pointer2);
int employee_sortBySector(void* pointer1 , void* pointer2);
int employee_sort(LinkedList* this);

int employee_averageSalary(LinkedList* this);

#endif
