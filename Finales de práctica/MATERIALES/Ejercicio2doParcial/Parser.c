#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    Empleado* auxEmpleado;
    FILE* pFile;
    pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
            auxEmpleado = em_newParametros(id,nombre,horasTrabajadas);
            al_add(listaEmpleados, auxEmpleado);
        }
        return 1;
    }
    return -1;
}

