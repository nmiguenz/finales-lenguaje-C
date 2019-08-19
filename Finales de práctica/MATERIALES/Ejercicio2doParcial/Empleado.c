#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"

int em_trabajaMasDe120Horas(void* item)
{
    int horasTrabajadasE;

    Empleado* hEm = (Empleado*)item;

    em_getHorasTrabajadas(hEm, &horasTrabajadasE);

    if(horasTrabajadasE > 120)
    {
        return 1;
    }
    return 0;
}


static int isValidName(char* name);
static int isValidHorasTrabajadas(int horasTrabajadas);


Empleado* em_new(void)
{

    Empleado* returnAux = (Empleado*) malloc(sizeof(Empleado));
    return returnAux;

}


Empleado* em_newParametros(char* strId,char* name, char* strHorasTrabajadas)
{
    int id;
    int horasTrabajadas;
    Empleado* this = em_new();

    id = atoi(strId);
    horasTrabajadas = atoi(strHorasTrabajadas);

    if( !em_setId(this,id) &&
        !em_setName(this,name) &&
        !em_setHorasTrabajadas(this,horasTrabajadas))
    {
        return this;
    }
    em_delete(this);
    return NULL;
}


void em_delete(Empleado* this)
{
    if(this != NULL)
        free(this);
}


//---------------------------------------------------------------


int em_setId(Empleado* this, int id)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            ultimoId++;
            this->id = ultimoId;
            retorno = 0;
        }
        if(id > ultimoId)
        {
            ultimoId = id;
            this->id = ultimoId;
            retorno = 0;
        }
    }
    return retorno;
}


int em_getId(Empleado* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}


int em_setName(Empleado* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}


int em_getName(Empleado* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}


int em_setHorasTrabajadas(Empleado* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas))
    {
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


int em_getHorasTrabajadas(Empleado* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}


//---------------------------------------------------------------


static int isValidName(char* name)
{
    int i = 0;
    if(strlen(name) < 128)
    {
        while(name[i] != '\0')
        {
            if((name[i] == ',') || (name[i] == '.'))
                return -1;
            i++;
        }
    }
    return 1;
}


static int isValidHorasTrabajadas(int horasTrabajadas)
{
    if(horasTrabajadas < 0 || horasTrabajadas > 600)
        return -1;
    return 1;
}
