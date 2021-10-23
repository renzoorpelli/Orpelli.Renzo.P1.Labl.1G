#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipo( eTipo tipos[], int tamT);

int validarIdTipo( int id, eTipo tipos[], int tamT);

int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo, char descripcion[]);
