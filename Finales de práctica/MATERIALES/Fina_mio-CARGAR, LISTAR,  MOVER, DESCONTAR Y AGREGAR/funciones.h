#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

int imprimirProductos (void* producto);
int moverProductos_depositos(ArrayList* pDep1, ArrayList* pDep2);
int descontarProductos(ArrayList* pDep1, ArrayList* pDep2);
int agregarProductos (ArrayList* pDep1, ArrayList* pDep2);

#endif // FUNCIONES_H_INCLUDED
