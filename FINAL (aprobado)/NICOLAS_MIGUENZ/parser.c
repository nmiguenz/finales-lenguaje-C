#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayList.h"
#include "parser.h"
#include "envio.h"
#include "utn.h"

int parserProductos(char* path , ArrayList* this)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bId[4096];
    char nombreProducto[4096];
    char bKmRecorridos[4096];
    char bTipoEntrega[4096];
    int id_envio;
    int kmRecorridos;
    int tipoEntrega;
    int contador=0;
    EEnvio* auxiliarEnvio;

    if(pFile != NULL && al_isEmpty(this))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,nombreProducto,bKmRecorridos,bTipoEntrega); /*Linea que no se copia (en el archivo era el t[itulo que estaba en blanco)*/
        retorno = 0;
       do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,nombreProducto,bKmRecorridos,bTipoEntrega)==4)
            {
                id_envio=atoi(bId);
                kmRecorridos=atoi(bKmRecorridos);
                tipoEntrega=atoi(bTipoEntrega);
                auxiliarEnvio = envio_newConParametros(id_envio,nombreProducto,kmRecorridos,tipoEntrega);
                al_add(this,auxiliarEnvio);
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

int parser_guardar(char* path , ArrayList* pArraylistEnvio)
{
    int retorno =-1;
    int id_envio;
    char nombre[4000];
    int kmRecorridos;
    int tipoEntrega;
    char textoEntrega[4096];
    int costoEnvio;

    EEnvio* this;
    int i;
    FILE* pFile;
    pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id_envio,nombre_producto,km_recorrido,tipo_entrega,costo_envio\n");
        for(i=0; i<al_len(pArraylistEnvio);i++)
        {
            retorno = 0;
            this = al_get(pArraylistEnvio, i);
            envio_getId_envio(this,&id_envio);
            envio_getNombre(this,nombre);
            envio_getKmRecorridos(this,&kmRecorridos);
            if(kmRecorridos < 50 )
            {
                envio_getTipoEntrega(this, &tipoEntrega);
                if (tipoEntrega==1)
                {
                    costoEnvio = 330+(kmRecorridos*67);
                    strcpy(textoEntrega, "normal");
                }
                else if (tipoEntrega==2)
                {
                    costoEnvio = 560+(kmRecorridos*67);
                    strcpy(textoEntrega, "express");
                }
                else if (tipoEntrega==3)
                {
                    costoEnvio = 80+(kmRecorridos*67);
                    strcpy(textoEntrega, "Segun disponibilidad");
                }

            }
            else
            {
                envio_getTipoEntrega(this, &tipoEntrega);
                if (tipoEntrega==1)
                {
                    costoEnvio = 330+(kmRecorridos*80);
                    strcpy(textoEntrega, "normal");
                }
                else if (tipoEntrega==2)
                {
                    costoEnvio = 560+(kmRecorridos*80);
                    strcpy(textoEntrega, "express");
                }
                else if (tipoEntrega==3)
                {
                    costoEnvio = 80+(kmRecorridos*80);
                    strcpy(textoEntrega, "Segun disponibilidad");
                }
            }
            fprintf(pFile, "%d,%s,%d,%s,%d\n", id_envio, nombre, kmRecorridos,textoEntrega,costoEnvio);
        }
        fclose(pFile);
    }
    return retorno;
}
