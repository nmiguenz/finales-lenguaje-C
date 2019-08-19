#ifndef DEPOSITO1_H_INCLUDED
#define DEPOSITO1_H_INCLUDED
typedef struct
{
    int prodcuto;
    char descripcion[500];
    int cantidad;
}EDeposito1;

EDeposito1* deposito1_new();
void deposito1_delete();
EDeposito1* deposito1_newConParametros(int prodcuto,char* descripcion,int cantidad);

int deposito1_setProdcuto(EDeposito1* this,int prodcuto);
int deposito1_getProdcuto(EDeposito1* this,int* prodcuto);

int deposito1_setDescripcion(EDeposito1* this,char* descripcion);
int deposito1_getDescripcion(EDeposito1* this,char* descripcion);

int deposito1_setCantidad(EDeposito1* this,int cantidad);
int deposito1_getCantidad(EDeposito1* this,int* cantidad);
#endif // DEPOSITO1_H_INCLUDED
