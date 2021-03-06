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
#define UP 1
#define DOWN 0

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
		if(utn_getName(bufferEmployee.name,NAME_LEN,"\nIngrese nombre: ","\nError, debe ingresar un nombre", 3)==SUCCESS &&
			utn_getName(bufferEmployee.lastName,NAME_LEN,"\nIngrese apellido: ","\nError, debe ingresar un apellido", 3)==SUCCESS &&
			utn_getFloatNumber(&bufferEmployee.salary, "\nIngrese salario: ","\nError, debe ingresar un salario valido",0,FLT_MAX,3)==SUCCESS &&
			utn_getNumber(&bufferEmployee.sector, "\nIngrese sector: ","\nError, debe ingresar un sector valido",0,INT_MAX,3)==SUCCESS &&
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
	int index;

	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>=0 && sector>0)//I don't ask if there is space because I already check it when I ask for the data
	{
		index = findEmptyIndex(list,len);
		list[index].id = id;
		strncpy(list[index].name, name,NAME_LEN);
		strncpy(list[index].lastName,lastName,NAME_LEN);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;
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
	if(list!=NULL && len>0 && id>0 && index != ERROR && list[index].isEmpty == FALSE)
	{
		do {
			if(utn_getNumber(&option,"\n\nIngrese una opcion: "
					"\n1.Modificar Nombre "
					"\n2.Modificar Apellido "
					"\n3.Modificar Salario "
					"\n4.Modificar Sector"
					"\n5.Volver al menu principal\n", "Error, elija una opcion valida\n", 1, 5, 3)==SUCCESS) {
				switch(option)
				{
				case 1:
					if(utn_getName(bufferEmployee.name,NAME_LEN,"\nIngrese nombre: ","\nError, debe ingresar un nombre", 3)==SUCCESS) {
						strncpy(list[index].name,bufferEmployee.name,NAME_LEN);
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				case 2:
					if(utn_getName(bufferEmployee.lastName,NAME_LEN,"\nIngrese apellido: ","\nError, debe ingresar un apellido", 3)==SUCCESS) {
						strncpy(list[index].lastName,bufferEmployee.lastName,NAME_LEN);
					result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				case 3:
					if(utn_getFloatNumber(&bufferEmployee.salary, "\nIngrese salario: ","\nError, debe ingresar un salario valido",0,FLT_MAX,3)==SUCCESS) {
						list[index].salary = bufferEmployee.salary;
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				case 4:
					if(utn_getNumber(&bufferEmployee.sector, "\nIngrese sector: ","\nError, debe ingresar un sector valido",0,INT_MAX,3)==SUCCESS) {
						list[index].sector = bufferEmployee.sector;
						result = SUCCESS;
					} else {
						result = ERROR;
					}
					break;
				}
			}
		}while(option!=5);
	}
	return result;
}

int removeEmployee(Employee* list, int len, int id)
{
	int result = ERROR;
	int index;
	char bufferAnswer[10];

	index = findEmployeeById(list,len,id);
	if(list!=NULL && len>0 && id>0 && index != ERROR && list[index].isEmpty == FALSE)
	{
		if(utn_getName(bufferAnswer,10,"\nSeguro que desea eliminar? Debe ingresar 'Si' para proseguir con la baja ", "\nError,ingrese una respuesta valida.",3)== SUCCESS && strncasecmp(bufferAnswer,"si",10)==0)
		{
		list[index].isEmpty = TRUE;
		result = SUCCESS;
		}
	}
	return result;
}

int sortEmployees(Employee* list, int len, int order)
{
	int result = ERROR;
	int i;
	Employee aux;
	int disorderedState=1;

	if(list != NULL && len > 0 && (order==0 || order==1))
	{
		while(disorderedState)
		{
			disorderedState = 0;
			for(i = 0; i < (len - 1); i++)
			{
				if((order == UP && (strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)>0 ||
						(strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector > list[i + 1].sector))) ||
				   (order == DOWN && (strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)<0 ||
						(strncasecmp(list[i].lastName, list[i + 1].lastName,NAME_LEN)==0 && list[i].sector < list[i + 1].sector))))
				{
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					disorderedState = 1;
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
    	printf("\n%5s %15s %15s %10s %7s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
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
	int bufferTotalEmployeesAboveAverageSalary;

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
					if(utn_getNumber(&order,"\nIngrese en que orden quiere ver la lista [1-UP/0-DOWN]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS &&
							sortEmployees(list, len,order)== SUCCESS)
					{
						printEmployees(list, len);
						result = SUCCESS;
					}
					break;
				case 2:
					if(totalSalary(list,len,&bufferTotalSalary)==SUCCESS && averageSalary(list,len,&bufferAverageSalary)==SUCCESS)
					{
						printf("\nEl salario total es: %.2f \nEl salario promedio es: %.2f\n",bufferTotalSalary,bufferAverageSalary);
					}
					printf("\nLos empleados que superan el salario promedio son: \n"
							"\n%5s %15s %15s %10s %5s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
					if(printEmployeesAboveAverageSalary(list,len,&bufferTotalEmployeesAboveAverageSalary)==SUCCESS)
					{
						printf("\n\nCantidad total: %d",bufferTotalEmployeesAboveAverageSalary);
					}
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
				break;//there is no need to keep asking, since I just found that at list there is one employee in the array
			}
		}
	}
	return result;
}

int hardCodeData(Employee* list, int* id)
{
	int result = ERROR;
	char name[][NAME_LEN] = {"Mike","Eleven","Dustin","Will","Max","Lucas","Nancy","Steve","Jonathan","Joyce","Jim"};
	char lastName[][NAME_LEN] = {"Whealer","Hooper","Henderson","Byers","Mayfield","Sinclair","Whealer","Harrington","Byers","Byers","Hooper"};
	float salary[] = {500,200,300,400,200,500,700,200,300,400,500};
	int sector[] = {1,1,2,5,3,1,2,6,4,7,7};
	int i;

	if(list!=NULL && id!=NULL)
	{
		for(i=0;i<11;i++)
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

int printEmployeesAboveAverageSalary(Employee* list, int len, int* qtyEmployeesAboveAverageSalary)
{
	int result = ERROR;
	float bufferAverageSalary;
	int i;
	int qtyEmployee=0;

	if(averageSalary(list,len,&bufferAverageSalary)==SUCCESS)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary >= bufferAverageSalary)
			{
				printOneEmployee(list[i]);
				qtyEmployee++;
			}
		}
		*qtyEmployeesAboveAverageSalary = qtyEmployee;
		result = SUCCESS;
	}
	return result;
}
