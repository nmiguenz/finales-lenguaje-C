#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "cliente.h"

int parser_leer(char* path , ArrayList* this)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bProducto[4096];
    char bDescripcion[4096];
    char bCantidad[4096];
    int producto;
    int cantidad;
    int contador=0;
    EDeposito1* auxiliarProducto;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad); /*Linea que no se copia (en el archivo era el t[itulo que estaba en blanco)*/
        retorno = 0;
       do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bProducto,bDescripcion,bCantidad)==3)
            {
                producto=atoi(bProducto);
                cantidad=atoi(bCantidad);
                auxiliarProducto = deposito1_newConParametros(producto,bDescripcion,cantidad);
                al_add(this,auxiliarProducto);
                contador++;
            }
            else
                printf("Error al leer los datos en el parser");

        }while(!feof(pFile));
        printf("Cantidad de datos leidos %d\n",contador);
    }
    else
        printf("No se pudo encontrar el archivo");

    return retorno;
}
/*
int parserEmployee(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    char id[4000];
    char nombre[4000];
    char apellido[4000];
    char email[4000];
    char genero;
    char profesion[4000];
    char usuario[4000];
    char nacionalidad[4000];
    Cliente* auxCliente;

    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile != NULL && al_isEmpty(pArrayListEmployee))
    {
        retorno =0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
               id, nombre, apellido, email, email, profesion, usuario, nacionalidad);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%c,%[^,],%[^,],%[^\n]\n",
                   id, nombre, apellido, email, &genero, profesion, usuario, nacionalidad);
            auxCliente = cliente_newParametros("-1", nombre, apellido, email, genero, profesion, usuario, nacionalidad);
            al_add(pArrayListEmployee, auxCliente);
        }
        fclose(pFile);
    }
    return retorno;
}
*/
int parser_guardar(char* path , ArrayList* pArrayListEmployee)
{
    int retorno =-1;
    int id;
    char nombre[4000];
    char apellido[4000];
    char email[4000];
    char genero;
    char profesion[4000];
    char usuario[4000];
    char nacionalidad[4000];

    Cliente* this;
    int i;
    FILE* pFile;
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,apellido,email,genero,profesion,usuario,nacionalidad\n");
        for(i=0; i<al_len(pArrayListEmployee);i++)
        {
            retorno = 0;
            this = al_get(pArrayListEmployee, i);
            cliente_getId(this,&id);
            cliente_getNombre(this,nombre);
            cliente_getApellido(this,apellido);
            cliente_getEmail(this,email);
            cliente_getGenero(this, &genero);
            cliente_getProfesion(this, profesion);
            cliente_getUsuario(this, usuario);
            cliente_getNacionalidad(this, nacionalidad);
            fprintf(pFile, "%d,%s,%s,%s,%c,%s,%s,%s\n", id, nombre, apellido, email, genero, profesion, usuario, nacionalidad);
        }
        fclose(pFile);
    }
    return retorno;
}
