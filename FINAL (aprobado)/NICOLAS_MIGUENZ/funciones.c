#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "ArrayList.h"
#include "utn.h"
#include "envio.h"

/** \brief Imprime los los campos de envio con modificaciones de costo y tipo Entrega
 *
 * \param puntero a void
 * \param
 * \return return 0 [OK] 1 [ERROR]
 *
 */
int imprimirProductos (void* envio)
{
    int auxId_envio;
    char auxNombre[4096];
    int auxKmRecorridos;
    int auxTipoEntrega;
    char textoEntrega[4096];
    int total;

    int retorno = 1;

    if (envio != NULL)
    {
        envio_getId_envio(envio, &auxId_envio);
        envio_getNombre(envio,auxNombre);
        envio_getKmRecorridos(envio, &auxKmRecorridos);

        if(auxKmRecorridos < 50 )
        {
            envio_getTipoEntrega(envio, &auxTipoEntrega);
            if (auxTipoEntrega==1)
            {
                total = 330+(auxKmRecorridos*67);
                strcpy(textoEntrega, "normal");
            }
            else if (auxTipoEntrega==2)
            {
                total = 560+(auxKmRecorridos*67);
                strcpy(textoEntrega, "express");
            }
            else if (auxTipoEntrega==3)
            {
                total = 80+(auxKmRecorridos*67);
                strcpy(textoEntrega, "Segun disponibilidad");
            }

        }
        else
        {
            envio_getTipoEntrega(envio, &auxTipoEntrega);
            if (auxTipoEntrega==1)
            {
                total = 330+(auxKmRecorridos*80);
                strcpy(textoEntrega, "normal");
            }
            else if (auxTipoEntrega==2)
            {
                total = 560+(auxKmRecorridos*80);
                strcpy(textoEntrega, "express");
            }
            else if (auxTipoEntrega==3)
            {
                total = 80+(auxKmRecorridos*80);
                strcpy(textoEntrega, "Segun disponibilidad");
            }
        }
        printf("----------------------------\n");
        printf("Id_Envio %d\n",auxId_envio);
        printf("Nombre: %s\n",auxNombre);
        printf("Km Recorridos: %d\n",auxKmRecorridos);
        printf("Tipo Entrega: %s\n",textoEntrega);
        printf("Costo Envio: %d\n", total);

        retorno = 0;
    }
    return retorno;
}
