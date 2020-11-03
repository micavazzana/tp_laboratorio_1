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
			employee_setHorasTrabajadasTxt(pEmployee,workedHoursStr);
			employee_setSueldoTxt(pEmployee,salaryStr);
			employee_setIdTxt(pEmployee,idStr);
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
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
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
	if (this != NULL && name != NULL && isValidCompoundName(name, NAME_LEN))
	{
		strncpy(this->nombre, name, NAME_LEN);
		result = SUCCESS;
	}
	return result;
}

int employee_getNombre(Employee* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->nombre, NAME_LEN);
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

int employee_setHorasTrabajadasTxt(Employee* this, char* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL && isValidNumber(workedHours, sizeof(workedHours)))
    {
        this->horasTrabajadas = atoi(workedHours);
        result = SUCCESS;
    }
    return result;
}

int employee_getHorasTrabajadasTxt(Employee* this, char* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL)
    {
        sprintf(workedHours, "%d", this->horasTrabajadas);
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

int employee_setSueldoTxt(Employee* this, char* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL && isValidNumberFloat(salary, sizeof(salary)))
    {
        this->sueldo = atof(salary);
        result = SUCCESS;
    }
    return result;
}

int employee_getSueldoTxt(Employee* this, char* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL)
    {
        sprintf(salary, "%.2f", this->sueldo);
        result = SUCCESS;
    }
    return result;
}

int employee_compareByName(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	char bufferFirstEmployee[NAME_LEN];
	char bufferSecondEmployee[NAME_LEN];

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		Employee* first = (Employee*)firstEmployee;
		Employee* second = (Employee*)SecondEmployee;
		employee_getNombre(first,bufferFirstEmployee);
		employee_getNombre(second,bufferSecondEmployee);
		if(strncasecmp(bufferFirstEmployee, bufferSecondEmployee, NAME_LEN) > 0)
		{
			result = 1;
		} else if (strncasecmp(bufferFirstEmployee, bufferSecondEmployee, NAME_LEN) < 0) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}

int employee_compareByWorkedHours(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	int bufferFirstEmployee;
	int bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		Employee* first = (Employee*)firstEmployee;
		Employee* second = (Employee*)SecondEmployee;
		employee_getHorasTrabajadas(first,&bufferFirstEmployee);
		employee_getHorasTrabajadas(second,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}
int employee_compareBySalary(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	float bufferFirstEmployee;
	float bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		Employee* first = (Employee*)firstEmployee;
		Employee* second = (Employee*)SecondEmployee;
		employee_getSueldo(first,&bufferFirstEmployee);
		employee_getSueldo(second,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}
int employee_compareById(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	int bufferFirstEmployee;
	int bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		Employee* first = (Employee*)firstEmployee;
		Employee* second = (Employee*)SecondEmployee;
		employee_getId(first,&bufferFirstEmployee);
		employee_getId(second,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}
