#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salaryStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdTxt(Employee* this, char* id);
int employee_getIdTxt(Employee* this, char* id);

int employee_setNombre(Employee* this, char* name);
int employee_getNombre(Employee* this, char* name);

int employee_setHorasTrabajadas(Employee* this, int workedHours);
int employee_getHorasTrabajadas(Employee* this, int* workedHours);

int employee_setSueldo(Employee* this, float salary);
int employee_getSueldo(Employee* this, float* salary);

#endif // employee_H_INCLUDED
