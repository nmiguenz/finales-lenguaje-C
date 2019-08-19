#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "deposito1.h"
#include "utn.h"

int codigoIngresadoPorUser;

int imprimirProductos (void* producto)
{
    int auxProducto;
    int auxCantidad;
    char descripcion[4092];
    int retorno = 1;

    if (producto != NULL)
    {
        deposito1_getProdcuto(producto,&auxProducto);
        deposito1_getCantidad(producto, &auxCantidad);
        deposito1_getDescripcion(producto, descripcion);

        printf("----------------------------\n");
        printf("Producto %d\n",auxProducto);
        printf("Descripcion: %s\n",descripcion);
        printf("Cantidad: %d\n",auxCantidad);
        retorno = 0;
    }
    return retorno;
}

int moverProductos_depositos(ArrayList* pDep1, ArrayList* pDep2)
{
    int numeroOrigen;
    int numeroDestino;
    int numeroProducto;
    int productoObtenido;
    int i;
    utn_getValidInt("Deposito Origen", "No es numero", &numeroOrigen, 1,2,2);
    utn_getValidInt("Deposito Destino", "No es numero", &numeroDestino, 1,2,2);
    if (numeroOrigen!=numeroDestino)
    {
        if (numeroOrigen ==  1)
        {
            numeroProducto = utn_getInt("ingrese codigo");
            for(i=0;i<al_len(pDep1);i++)
            {
              deposito1_getProdcuto(al_get(pDep1,i),&productoObtenido);
              if(productoObtenido==numeroProducto)
                al_add(pDep2,al_pop(pDep1,i));
            }

        }
        else if (numeroOrigen == 2)
        {
            numeroProducto = utn_getInt("ingrese codigo");
            for(i=0;i<al_len(pDep2);i++)
            {
              deposito1_getProdcuto(al_get(pDep2,i),&productoObtenido);
              if(productoObtenido==numeroProducto)
                al_add(pDep1,al_pop(pDep2,i));
            }
        }

    }
    return 0;
}

int descontarProductos(ArrayList* pDep1, ArrayList* pDep2)
{
    int numeroProducto;
    int productoObtenido;
    int cantidadADescontar;
    int cantidadEnDeposito;
    int resultado;
    int i;

    numeroProducto = utn_getInt("Ingrese codigo");

    for(i=0;i<al_len(pDep1);i++)
    {
        deposito1_getProdcuto(al_get(pDep1,i),&productoObtenido);
        if (numeroProducto == productoObtenido)
        {
            deposito1_getCantidad(al_get(pDep1,i), &cantidadEnDeposito);
            utn_getValidInt("Ingrese cantidad a descontar", "No es una cantidad valida", &cantidadADescontar,1,cantidadEnDeposito,3);
            resultado = cantidadEnDeposito - cantidadADescontar;
            deposito1_setCantidad(al_get(pDep1,i), resultado);
        }
    }
    for(i=0;i<al_len(pDep2);i++)
    {
        deposito1_getProdcuto(al_get(pDep2,i),&productoObtenido);
        if (numeroProducto == productoObtenido)
        {
            deposito1_getCantidad(al_get(pDep2,i), &cantidadEnDeposito);
            utn_getValidInt("Ingrese cantidad a descontar", "No es una cantidad valida", &cantidadADescontar,1,cantidadEnDeposito,3);
            resultado = cantidadEnDeposito - cantidadADescontar;
            deposito1_setCantidad(al_get(pDep2,i), resultado);
        }
    }
    return 0;
}

int agregarProductos (ArrayList* pDep1, ArrayList* pDep2)
{
    int codigoProducto;
    int codigoProductoObtenido;
    int cantidadAAgregar;
    int cantidadProductoExistente;
    int resultado=0;
    int i =0;
    int retorno = 1;

    codigoProducto = utn_getInt("Ingrese el codigo de producto: ");

    for (i=0; i<al_len(pDep1); i++)
    {
        deposito1_getProdcuto(al_get(pDep1,i),&codigoProductoObtenido);
        if (codigoProducto==codigoProductoObtenido)
        {
            utn_getValidInt("Ingrese la cantidad de producto a agregar: \n", "No es un numero o la cantidad no es valida (maximo:1000)\n",&cantidadAAgregar,1,1000,2);
            deposito1_getCantidad(al_get(pDep1,i),&cantidadProductoExistente);
            resultado = cantidadProductoExistente + cantidadAAgregar;
            deposito1_setCantidad(al_get(pDep1,i), resultado);
            retorno=0;
        }
    }
    for (i=0; i<al_len(pDep2); i++)
    {
        deposito1_getProdcuto(al_get(pDep2,i),&codigoProductoObtenido);
        if (codigoProducto==codigoProductoObtenido)
        {
            utn_getValidInt("Ingrese la cantidad de producto a agregar: \n", "No es un numero o la cantidad no es valida (maximo:1000)\n",&cantidadAAgregar,1,1000,2);
            deposito1_getCantidad(al_get(pDep2,i),&cantidadProductoExistente);
            resultado = cantidadProductoExistente + cantidadAAgregar;
            deposito1_setCantidad(al_get(pDep2,i), resultado);
            retorno=0;
        }
    }
    return retorno;
}
