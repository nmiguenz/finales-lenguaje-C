#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "ArrayList.h"
#include "deposito1.h"
#include "utn.h"
#include "funciones.h"
    /***
* 1- Cargar depositos: Se deberan leer ambos archiuos y generar dos Arraylist con los datos.
* 2- Listar productos de deposito: Se le pedira al usuario el numero de deposito (1 o 2) y se imprimira la lista de productos en dicho deposito.
* 3- Mover productos a deposito: Se le pedira al usuario que ingrese el numero de deposito origen y luego el numero de deposito destino. Luego se le pedira al usuario que ingrese el
* codigo del producto a mover(debera existir en el deposito origen). Los productos deberan borrarse del deposito origen y agregarse al deposito destino.
* (Esta operacion se hace sobre la cantidad total de los productos, no puede quedar el mismo codigo de producto en ambos depositos).
* 4- Descontar productos de deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Se le pedira al usuario que ingrese
* la cantidad de productos a descontar y dicha cantidad se restara a la cantidad actual de productos de ese tipo en el deposito correspondiente,
* si es que existe esa cantidad disponible.
* 5- Agregar productos a deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Luego se le pedira al usuario que ingrese
* la camntidad de productos a sumar y dicha cantidad se sumara a la cantidad actual de productos de ese tipo en el deposito correspondiente.
* 6- Salir.
*
* NOTA: Cada vez que se haga una modificacion sobre un deposito, la misma se debe reflejarse en el archivo csv correspondiente a dicho deposito
* El cambio no puede realizarse solo en el ArrayList.
***/

int main()
{
   ArrayList* pElementosDeposito1 = al_newArrayList();
   ArrayList* pElementosDeposito2 = al_newArrayList();

   int menu;
   int numeroValidacion;


    do
    {
        menu = utn_menuDeOpciones();
        switch(menu)
        {
        case 1:
            parserProducto("dep0.csv", pElementosDeposito1);
            parserProducto("dep1.csv", pElementosDeposito2);
            break;
        case 2:
            utn_getValidInt("Numero", "No es numero", &numeroValidacion, 1,2,2);
            if (numeroValidacion==1)
                al_map(pElementosDeposito1, imprimirProductos);
            else if (numeroValidacion==2)
                al_map(pElementosDeposito2, imprimirProductos);
            break;
        case 3:
            moverProductos_depositos(pElementosDeposito1,pElementosDeposito2);
            break;
        case 4:
            descontarProductos(pElementosDeposito1, pElementosDeposito2);
            break;
        case 5:
            agregarProductos(pElementosDeposito1, pElementosDeposito2);
            break;
        }

    }
    while(menu!=6);
    return 0;
}
