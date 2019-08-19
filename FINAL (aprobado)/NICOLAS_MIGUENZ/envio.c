#include "envio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EEnvio* envio_new()
{
    EEnvio* this;
    this=malloc(sizeof(EEnvio));
    return this;
}

void envio_delete(EEnvio* this)
{
    free(this);
}

EEnvio* envio_newConParametros(int id_envio,char* nombre,int kmRecorridos,int tipoEntrega)
{
    EEnvio* this;
    this=envio_new();

    if(
    !envio_setId_envio(this,id_envio)&&
    !envio_setNombre(this,nombre)&&
    !envio_setKmRecorridos(this,kmRecorridos)&&
    !envio_setTipoEntrega(this,tipoEntrega))
        return this;

    envio_delete(this);
    return NULL;
}

int envio_setId_envio(EEnvio* this,int id_envio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_envio=id_envio;
        retorno=0;
    }
    return retorno;
}

int envio_getId_envio(EEnvio* this,int* id_envio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_envio=this->id_envio;
        retorno=0;
    }
    return retorno;
}

int envio_setNombre(EEnvio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int envio_getNombre(EEnvio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int envio_setKmRecorridos(EEnvio* this,int kmRecorridos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->kmRecorridos=kmRecorridos;
        retorno=0;
    }
    return retorno;
}

int envio_getKmRecorridos(EEnvio* this,int* kmRecorridos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *kmRecorridos=this->kmRecorridos;
        retorno=0;
    }
    return retorno;
}

int envio_setTipoEntrega(EEnvio* this,int tipoEntrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->tipoEntrega=tipoEntrega;
        retorno=0;
    }
    return retorno;
}

int envio_getTipoEntrega(EEnvio* this,int* tipoEntrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tipoEntrega=this->tipoEntrega;
        retorno=0;
    }
    return retorno;
}

