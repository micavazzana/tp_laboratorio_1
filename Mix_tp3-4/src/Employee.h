#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NAME_LEN 128
typedef struct
{
    int id;
    char nombre[NAME_LEN];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salaryStr);
void employee_delete(Employee* this);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdTxt(Employee* this, char* id);
int employee_getIdTxt(Employee* this, char* id);
int employee_setNombre(Employee* this, char* name);
int employee_getNombre(Employee* this, char* name);
int employee_setHorasTrabajadas(Employee* this, int workedHours);
int employee_getHorasTrabajadas(Employee* this, int* workedHours);
int employee_setHorasTrabajadasTxt(Employee* this, char* workedHours);
int employee_getHorasTrabajadasTxt(Employee* this, char* workedHours);
int employee_setSueldo(Employee* this, float salary);
int employee_getSueldo(Employee* this, float* salary);
int employee_setSueldoTxt(Employee* this, char* salary);
int employee_getSueldoTxt(Employee* this, char* salary);
int employee_compareByName(void*, void*);
int employee_compareByWorkedHours(void*, void*);
int employee_compareBySalary(void*, void*);
int employee_compareById(void*, void*);
int employee_IdParImpar(void* pEmployee);

#endif // employee_H_INCLUDED
