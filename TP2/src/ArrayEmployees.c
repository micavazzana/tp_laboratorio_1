/*
 * ArrayEmployees.c
 *
 *  Created on: 25 sep. 2020
 *      Author: micavazzana
 */
#include"ArrayEmployees.h"
#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define UP 0
#define DOWN 1

int initEmployees(Employee* list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=TRUE;
		}
		result=SUCCESS;
	}
	return result;
}

int findEmptyIndex(Employee* list, int len)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int loadUpEmployee(Employee* list, int len,int* id)
{
	int result= ERROR;
	Employee bufferEmployee;

	if(list!=NULL && len>0 && id!=NULL && findEmptyIndex(list,len)!=ERROR)//in addition to validating the parameters, ensures that there is room before making the user load data
	{
		if(utn_getName(bufferEmployee.name,NAME_LEN,"\nIngrese nombre: ","\nError", 3)==SUCCESS &&
			utn_getName(bufferEmployee.lastName,NAME_LEN,"\nIngrese apellido: ","\nError", 3)==SUCCESS &&
			utn_getFloatNumber(&bufferEmployee.salary, "\nIngrese salario: ","\nError",0,FLT_MAX,3)==SUCCESS &&
			utn_getNumber(&bufferEmployee.sector, "\nIngrese sector: ","\nError",0,INT_MAX,3)==SUCCESS &&
			addEmployee(list,len,*id,bufferEmployee.name,bufferEmployee.lastName,bufferEmployee.salary,bufferEmployee.sector)==SUCCESS)
		{
			(*id)++;
			result = SUCCESS;
		}
	}
	return result;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int result = ERROR;
	Employee bufferEmployee;
	int index;

	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>=0 && sector>0)//I don't ask if there is space because I already check it when I ask for the data
	{
		bufferEmployee.id = id;
		strncpy(bufferEmployee.name, name,NAME_LEN);
		strncpy(bufferEmployee.lastName,lastName,NAME_LEN);
		bufferEmployee.salary = salary;
		bufferEmployee.sector = sector;
		bufferEmployee.isEmpty = FALSE;
		index = findEmptyIndex(list,len);
		list[index] = bufferEmployee;
		result = SUCCESS;
	}
	return result;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int result = ERROR;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}

int modifyEmployee(Employee* list, int len, int id)
{
	int result = ERROR;
	int index;
	int option;
	Employee bufferEmployee;

	index = findEmployeeById(list,len,id);
	if(list!=NULL && len>0 && id>0 && index != ERROR)
	{
		do {
			if(utn_getNumber(&option,"\n\nIngrese una opcion: "
					"\n1.Modificar Nombre "
					"\n2.Modificar Apellido "
					"\n3.Modificar Salario "
					"\n4.Modificar Sector"
					"\n5.Volver al menu principal\n",
					"Error, elija una opcion valida\n", 1, 5, 3)==SUCCESS) {
				switch(option)
				{
				case 1:
					if(utn_getName(bufferEmployee.name,NAME_LEN,"\nIngrese nombre: ","\nError", 3)==SUCCESS)
					{
						strncpy(list[index].name,bufferEmployee.name,NAME_LEN);
					}
					break;
				case 2:
					if(utn_getName(bufferEmployee.lastName,NAME_LEN,"\nIngrese apellido: ","\nError", 3)==SUCCESS)
					{
						strncpy(list[index].lastName,bufferEmployee.lastName,NAME_LEN);
					}
					break;
				case 3:
					if(utn_getFloatNumber(&bufferEmployee.salary, "\nIngrese salario: ","\nError",0,FLT_MAX,3)==SUCCESS)
					{
						list[index].salary = bufferEmployee.salary;
					}
					break;
				case 4:
					if(utn_getNumber(&bufferEmployee.sector, "\nIngrese sector: ","\nError",0,INT_MAX,3)==SUCCESS)
					{
						list[index].sector = bufferEmployee.sector;
					}
					break;
				}
			}
		}while(option!=5);
		result = SUCCESS;
	}
	return result;
}

int removeEmployee(Employee* list, int len, int id)
{
	int result = ERROR;
	int index;

	index = findEmployeeById(list,len,id);
	if(list!=NULL && len>0 && id>0 && index != ERROR)
	{
		list[index].isEmpty = TRUE;
		result = SUCCESS;
	}
	return result;
}

int sortEmployees(Employee* list, int len, int order)
{
	int result = ERROR;
	int i;
	Employee aux;
	int disorderedState=1;

	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		while(disorderedState)//mientras este desordenado
		{
			disorderedState = 0;
			for(i = 0; i < (len - 1); i++)
			{
				switch(order) {
				case UP: //de la A a la Z y salario menor a mayor
					if(strncmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)>0 ||
							(strncmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector > list[i + 1].sector))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						disorderedState = 1;
					}
					break;
				case DOWN: //de la Z a la A y salario mayor a menor
					if(strncmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)<0 ||
							(strncmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector < list[i + 1].sector))
					{
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						disorderedState = 1;
					}
					break;
				}
			}
		}
		result = SUCCESS;
	}
	return result;
}

int printOneEmployee(Employee list)
{
	int result=ERROR;
	if(list.isEmpty == FALSE)
	{
		printf ("\n%5d %15s %15s %10.2f %5d",list.id,list.name,list.lastName,list.salary,list.sector);
		result=SUCCESS;
	}
	return result;
}

int printEmployees(Employee* list, int len)
{
    int result = ERROR;
    int i;

	if(list!=NULL && len>0)
    {
    	printf("\n%5s %15s %15s %10s %5s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
        for(i=0;i<len;i++)
        {
        	printOneEmployee(list[i]);
        }
        result = SUCCESS;
    }
    return result;
}

int inform(Employee* list, int len)
{
	int result = ERROR;
	int option;
	int order;
	float bufferTotalSalary;
	float bufferAverageSalary;

	if(list!=NULL && len>0)
	{
		do
		{
			if(utn_getNumber(&option,"\n\nIngrese una opcion: "
					"\n1.Ordenar y Mostrar "
					"\n2.Total y Promedio de los salarios e informe de empleados que superan el promedio"
					"\n3.Volver al menu principal ",
					"Error, elija una opcion valida\n", 1, 3, 3)==SUCCESS)
			{
				switch(option)
				{
				case 1:
					if(utn_getNumber(&order,"\nIngrese en que orden quiere ver la lista [0-UP/1-DOWN]: ","\nError",0,1,3)==SUCCESS)
					{
						sortEmployees(list, len,order);
						printEmployees(list, len);
						result = SUCCESS;
					}
					break;
				case 2:
					if(totalSalary(list,len,&bufferTotalSalary)==SUCCESS && averageSalary(list,len,&bufferAverageSalary)==SUCCESS)
					{
						printf("\nEl salario total es: %.2f \nEl salario promedio es: %.2f\n",bufferTotalSalary,bufferAverageSalary);
					}
					printf("\nLos empleados que superan el salario promedio son: \n");
					printf("\n%5s %15s %15s %10s %5s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
					printEmployeesAboveAverageSalary(list,len);
					break;
				}
			}
		}while(option!=3);
	}
	return result;
}

int isAnyData(Employee* list, int len)
{
	int i;
	int result = FALSE;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)//if there is data
			{
				result = TRUE;
			}
		}
	}
	return result;
}

int hardCodeData(Employee* list, int* id)
{
	int result = ERROR;
	char name[][NAME_LEN] = {"Mike","Eleven","Dustin","Will","Max","Lucas","Nancy","Steve","Jonathan","Joyce","Jim"};
	char lastName[][NAME_LEN] = {"Whealer","","Henderson","Byers","Mayfield","Sinclair","Whealer","Harrington","Byers","Byers","Hooper"};
	float salary[] = {500,200,300,400,200,500,700,200,300,400,500};
	int sector[] = {1,1,2,5,3,1,2,6,4,7,7};
	int i;

	if(list!=NULL && id!=NULL)
	{
		for(i=0;i<9;i++)
		{
			strcpy(list[i].name,name[i]);
			strcpy(list[i].lastName,lastName[i]);
			list[i].salary = salary[i];
			list[i].sector = sector[i];
			list[i].isEmpty = FALSE;
			list[i].id = *id;
			(*id)++;
		}
		result=SUCCESS;
	}
	return result;
}

int totalSalary(Employee* list, int len,float* finalTotalSalary)
{
	int result = ERROR;
	int i;
	float accumulator;

	if(list!=NULL && len>0 && finalTotalSalary!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				accumulator = accumulator + list[i].salary;
			}
		}
		*finalTotalSalary = accumulator;
		result=SUCCESS;
	}
	return result;
}

int averageSalary(Employee* list, int len, float* finalAverageSalary)
{
	int result = ERROR;
	float bufferTotalSalary;
	int i;
	int qtyEmployee=0;

	if(list!=NULL && len>0 && finalAverageSalary!=NULL)
	{
		if(totalSalary(list,len,&bufferTotalSalary)==SUCCESS)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == FALSE)
				{
					qtyEmployee++;
				}
			}
		}
		*finalAverageSalary = bufferTotalSalary/qtyEmployee;
		result=SUCCESS;
	}
	return result;
}

int printEmployeesAboveAverageSalary(Employee* list, int len)
{
	int result = ERROR;
	float bufferAverageSalary;
	int i;

	if(averageSalary(list,len,&bufferAverageSalary)==SUCCESS)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].salary >= bufferAverageSalary)
			{
				printOneEmployee(list[i]);
			}
		}
		result = SUCCESS;
	}
	return result;
}
