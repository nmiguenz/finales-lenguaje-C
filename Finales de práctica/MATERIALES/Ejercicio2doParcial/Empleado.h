#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char name[128];
  int horasTrabajadas;
};
typedef struct S_Empleado Empleado;

int em_trabajaMasDe120Horas(void* item);

Empleado* em_new(void);
Empleado* em_newParametros(char* strId,char* name, char* strHorasTrabajadas);
void em_delete(Empleado* this);

int em_setId(Empleado* this, int id);
int em_getId(Empleado* this, int* id);
int em_setName(Empleado* this, char* name);
int em_getName(Empleado* this, char* name);
int em_setHorasTrabajadas(Empleado* this, int horasTrabajadas);
int em_getHorasTrabajadas(Empleado* this, int* horasTrabajadas);

#endif // EMPLEADO_H_INCLUDED
