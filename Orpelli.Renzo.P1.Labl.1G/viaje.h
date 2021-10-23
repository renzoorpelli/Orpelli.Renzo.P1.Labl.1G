#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include "fecha.h"
#include "micros.h"
#include "empresas.h"
#include "destino.h"
#include "tipo.h"
typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;

#endif // VIAJE_H_INCLUDED

int inicializarViaje(eViaje viajes[], int tamV);
int buscarLibreViaje(eViaje viajes[], int tamV);
int altaViaje(eViaje viajes[], int tamV,eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,int* pIdViajes);
int mostrarViajes( eViaje viajes[], int tamV ,eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
