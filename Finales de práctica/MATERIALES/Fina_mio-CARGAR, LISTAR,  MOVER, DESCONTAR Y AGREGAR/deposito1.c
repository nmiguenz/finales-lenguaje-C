#include "deposito1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EDeposito1* deposito1_new()
{
    EDeposito1* this;
    this=malloc(sizeof(EDeposito1));
    return this;
}

void deposito1_delete(EDeposito1* this)
{
    free(this);
}

EDeposito1* deposito1_newConParametros(int prodcuto,char* descripcion,int cantidad)
{
    EDeposito1* this;
    this=deposito1_new();

    if(
    !deposito1_setProdcuto(this,prodcuto)&&
    !deposito1_setDescripcion(this,descripcion)&&
    !deposito1_setCantidad(this,cantidad))
        return this;

    deposito1_delete(this);
    return NULL;
}

int deposito1_setProdcuto(EDeposito1* this,int prodcuto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->prodcuto=prodcuto;
        retorno=0;
    }
    return retorno;
}

int deposito1_getProdcuto(EDeposito1* this,int* prodcuto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *prodcuto=this->prodcuto;
        retorno=0;
    }
    return retorno;
}

int deposito1_setDescripcion(EDeposito1* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int deposito1_getDescripcion(EDeposito1* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int deposito1_setCantidad(EDeposito1* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int deposito1_getCantidad(EDeposito1* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

