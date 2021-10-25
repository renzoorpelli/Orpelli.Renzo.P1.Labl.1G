#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataWarehouse.h"

int capacidad[10] = {15,15,23,30,23,25,22,25,22,25};

int idMicro[10] = {1000,1001,1002,1003,1003,1003,1003,1000,1002,1002};

int idTipoPasaje[10] = {5000,5002,5003,5001,5002,5001,5000,5000,5001,5001};

int idViajes[10] = {10000,10001,10002,10003,10003,10003,10003,10000,10002,10002};

int idDestinos[10] = {20003,20000,20003,20002,20001,20003,20000,20000,20002,20000};

int fechasdia[10] =  {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

int fechasmes[10] = {02, 02, 02, 02, 02, 02, 02, 02, 02, 02};

int fechasanio[10] = {2003, 2005, 2007, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

int hardcodeaMicros(eMicro lista[], int tam, int cant,int* pId)
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idEmpresa = idMicro[i];
            lista[i].idTipo = idTipoPasaje[i];
            lista[i].capacidad = capacidad[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}


int hardcodeaViajes(eViaje viajes[], int tamV, int cant, int* pId)
{
    int contador = -1;
    if (viajes != NULL && tamV > 0 && cant >= 0 && cant <= tamV && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            viajes[i].id = *pId;
            (*pId)++;
            viajes[i].idMicro = idViajes[i];
            viajes[i].idDestino = idDestinos[i];
            viajes[i].fecha.dia = fechasdia[i];
            viajes[i].fecha.mes = fechasmes[i];
            viajes[i].fecha.anio = fechasanio[i];
            viajes[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}

