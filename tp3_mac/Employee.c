#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"
#define ERROR -1
#define SUCCESS 0

Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salaryStr)
{
	Employee* pEmployee = NULL;

	if (idStr != NULL && nameStr != NULL && workedHoursStr != NULL && salaryStr != NULL)
	{
		pEmployee = employee_new();
		if (pEmployee != NULL)
		{
			employee_setNombre(pEmployee,nameStr);
			employee_setHorasTrabajadas(pEmployee,atoi(workedHoursStr));
			employee_setSueldo(pEmployee,atof(salaryStr));
			employee_setId(pEmployee,atoi(idStr));
		}
	}
	return pEmployee;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this, int id)
{
	int result = ERROR;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		result = SUCCESS;
	}
	return result;
}

int employee_getId(Employee* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        result = SUCCESS;
    }
    return result;
}

int employee_setIdTxt(Employee* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, 1000))
    {
        this->id = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int employee_getIdTxt(Employee* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->id);
        result = SUCCESS;
    }
    return result;
}

int employee_setNombre(Employee *this, char* name)
{
	int result = ERROR;
	if (this != NULL && name != NULL && isValidLetters(name,sizeof(name)))
	{
		strncpy(this->nombre, name, (int) sizeof(this->nombre));
		result = SUCCESS;
	}
	return result;
}

int employee_getNombre(Employee* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->nombre, (int)sizeof(name));
        result = SUCCESS;
    }
    return result;
}

int employee_setHorasTrabajadas(Employee* this, int workedHours)
{
	int result = ERROR;
	if(this != NULL && workedHours > 0)
	{
		this->horasTrabajadas = workedHours;
		result = SUCCESS;
	}
	return result;
}

int employee_getHorasTrabajadas(Employee* this, int* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL)
    {
        *workedHours = this->horasTrabajadas;
        result = SUCCESS;
    }
    return result;
}

int employee_setSueldo(Employee* this, float salary)
{
	int result = ERROR;
	if(this != NULL && salary > 0)
	{
		this->sueldo = salary;
		result = SUCCESS;
	}
	return result;
}

int employee_getSueldo(Employee* this, float* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL)
    {
        *salary = this->sueldo;
        result = SUCCESS;
    }
    return result;
}
