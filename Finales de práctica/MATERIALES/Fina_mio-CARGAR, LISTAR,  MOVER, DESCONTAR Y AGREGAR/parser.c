#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "deposito1.h"

int parserProducto(char* path , ArrayList* this)
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

    if(pFile != NULL && al_isEmpty(this))
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
