#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eDestino;

#endif // DESTINO_H_INCLUDED
int mostrarDestinos(eDestino destinos[], int tamD);
int validarIdDestino(int id, eDestino destinos[], int tamD);
int cargarDescripcionDestino( eDestino destinos[], int tamD, int idDestino, char descripcion[], float* precio);
