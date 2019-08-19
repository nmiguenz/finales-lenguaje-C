#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED
typedef struct
{
    int id_envio;
    char nombre[4096];
    int kmRecorridos;
    int tipoEntrega;
}EEnvio;

EEnvio* envio_new();
void envio_delete();
EEnvio* envio_newConParametros(int id_envio,char* nombre,int kmRecorridos,int tipoEntrega);

int envio_setId_envio(EEnvio* this,int id_envio);
int envio_getId_envio(EEnvio* this,int* id_envio);

int envio_setNombre(EEnvio* this,char* nombre);
int envio_getNombre(EEnvio* this,char* nombre);

int envio_setKmRecorridos(EEnvio* this,int kmRecorridos);
int envio_getKmRecorridos(EEnvio* this,int* kmRecorridos);

int envio_setTipoEntrega(EEnvio* this,int tipoEntrega);
int envio_getTipoEntrega(EEnvio* this,int* tipoEntrega);

#endif // ENVIO_H_INCLUDED
