#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eChofer;


#endif // CHOFER_H_INCLUDED
int mostrarChoferes( eChofer choferes[], int tamChof);


int validarIdChofer(int id,eChofer choferes[], int tamChof );


int cargarNombreChofer(eChofer choferes[], int tamChof, int idChofer, char nombre[], char* sexo);
