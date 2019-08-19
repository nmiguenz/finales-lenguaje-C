#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "ArrayList.h"
#include "envio.h"
#include "utn.h"
#include "funciones.h"

int main()
{
   ArrayList* pElementosEnvio = al_newArrayList();

   int menu;

    do
    {
        menu = utn_menuDeOpciones();
        switch(menu)
        {
        case 1:
            parserProductos("data_final2.csv", pElementosEnvio);
            break;
        case 2:
            al_map(pElementosEnvio, imprimirProductos);
            break;
        case 3:
            parser_guardar("archivo_generado.csv" , pElementosEnvio);
            break;
        }
    }
    while(menu!=4);
    return 0;
}
