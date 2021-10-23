#ifndef MICROS_H_INCLUDED
#define MICROS_H_INCLUDED
#include "empresas.h"
#include "tipo.h"
typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;

}eMicro;

#endif // MICROS_H_INCLUDED
int menu();
int inicializarMicros(eMicro lista[], int tam);
int buscarLibre(eMicro lista[], int tam);
int altaMicros(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pId);
void mostrarMicro( eMicro lista, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
int bajaMicroSistema(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
int buscarMicroId( eMicro lista[], int tam, int Id );
int modificarMicro(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
int menuModificar( eMicro lista[], int tam, int indice, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT );
int cargarEmpresaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, int idMicro, char empresa[]);
int cargarTipoMicro( eMicro lista[], int tam, eTipo tipos[], int tamT, int idMicro, char tipo[]);
