#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#define ERROR -1
#define SUCCESS 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (-1) ERROR - Si el puntero a LikedList es NULL o si el puntero al archivo es NULL o si no pudo añadir el empleado a la lista
 * 					  (0) EXITO
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee *pEmployee;
	char bufferHeader[500];
	char bufferId[500];
	char bufferName[500];
	char bufferWorkedHours[500];
	char bufferSalary[500];

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^\n]\n", bufferHeader);//for skipping the header
		do
		{
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferWorkedHours, bufferSalary) == 4)
			{
				pEmployee = employee_newParametros(bufferId, bufferName, bufferWorkedHours, bufferSalary);
				if (pEmployee != NULL)
				{
					result = ll_add(pArrayListEmployee, pEmployee);//ll_add returns 0 if Ok
				}
			} else {
				break;
			}
		} while (!feof(pFile));
	}
	return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (-1) ERROR - Si el puntero a LikedList es NULL o si el puntero al archivo es NULL o si no pudo añadir el empleado a la lista
 * 					  (0) EXITO
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee* pEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if (pEmployee != NULL && fread(pEmployee,sizeof(Employee),1,pFile)==1)
			{
				result = ll_add(pArrayListEmployee, pEmployee);//ll_add returns 0 if Ok
			} else {
				break;
			}
		} while (!feof(pFile));
	}
	return result;
}

/**
 * \brief Parsea los datos de los empleados al archivo data.csv(modo texto).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (0) EXITO (-1) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida.
 * \return int Return (-1) ERROR - Si el puntero a LikedList es NULL o si el puntero al archivo es NULL o si no pudo escribir el empleado al archivo
 * 					  (0) EXITO
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee *pEmployee;
	int bufferId;
	char bufferName[NAME_LEN];
	int bufferWorkedHours;
	float bufferSalary;
	int len;
	int i;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");
		for (i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL
					&& employee_getId(pEmployee, &bufferId) == SUCCESS
					&& employee_getNombre(pEmployee, bufferName) == SUCCESS
					&& employee_getSueldo(pEmployee, &bufferSalary) == SUCCESS
					&& employee_getHorasTrabajadas(pEmployee, &bufferWorkedHours) == SUCCESS)
			{
				fprintf(pFile, "%d,%s,%d,%f\n", bufferId, bufferName, bufferWorkedHours, bufferSalary);
			}
		}
		result = SUCCESS;
	}
	return result;
}

/**
 * \brief Parsea los datos de los empleados al archivo data.csv(modo binario).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (0) EXITO (-1) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida.
 * \return int Return (-1) ERROR - Si el puntero a LikedList es NULL o si el puntero al archivo es NULL o si no pudo escribir el empleado al archivo
 * 					  (0) EXITO
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee* pEmployee;
	int len;
	int i;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for (i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL)
			{
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		result = SUCCESS;
	}
	return result;
}
