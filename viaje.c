#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"



int inicializarViaje(eViaje viajes[], int tamV)
{
    int checkStatus = -1;
    if (viajes != NULL && tamV > 0)
    {
        for (int i = 0; i < tamV; i++)
        {
            viajes[i].isEmpty = 1;
        }
        checkStatus = 0;
    }

    return checkStatus;
}

int buscarLibreViaje(eViaje viajes[], int tamV)
{
    int checkStatus = -1;
    for (int i = 0; i < tamV; i++)
    {
        if (viajes[i].isEmpty)
        {
            checkStatus = i;
            break;
        }
    }

    return checkStatus;
}

int altaViaje(eViaje viajes[], int tamV,eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD, eChofer choferes[], int tamChof, int* pIdViajes)
{
    int checkStatus = 0;
    int indice;
    eViaje auxViaje;

    if( viajes != NULL && tamV > 0 &&lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0 && pIdViajes != NULL)
    {
        system("cls");
        printf("            ***ALTA VIAJES***     \n");
        indice = buscarLibreViaje(viajes, tamV);
        if (indice == -1)
        {
            printf("Errorr, no hay mas lugar\n");
        }
        else
        {
            auxViaje.id = *pIdViajes;
            (*pIdViajes)++;

            mostrarMicros(lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
            printf("Ingrese id micro:\n");
            scanf("%d", &auxViaje.idMicro);
            while(buscarMicroId(lista, tam, auxViaje.idMicro) == -1)
            {
                printf("Error ingrese un id de micro valido: \n");
                scanf("%d", &auxViaje.idMicro);
            }
            mostrarDestinos(destinos, tamD);
            printf("Ingrese id Servicios:\n");
            scanf("%d", &auxViaje.idDestino);
            while(!validarIdDestino(auxViaje.idDestino, destinos, tamD))
            {
                printf("Error ingrese un id de destino valido: \n");
                scanf("%d", &auxViaje.idDestino);
            }
            printf("Ingrese fecha:\n");
            scanf("%d/%d/%d", &auxViaje.fecha.dia,
                  &auxViaje.fecha.mes,
                  &auxViaje.fecha.anio);
            while(auxViaje.fecha.dia >30 && auxViaje.fecha.mes > 12 && auxViaje.fecha.anio > 2021)
            {
                printf("ERROR...Ingrese fecha:\n");
                scanf("%d/%d/%d", &auxViaje.fecha.dia,
                      &auxViaje.fecha.mes,
                      &auxViaje.fecha.anio);
            }

            auxViaje.isEmpty = 0;
            viajes[indice] = auxViaje;
            checkStatus = 1;

        }

    }

    return checkStatus;
}

void mostrarViaje( eViaje unViaje, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    char descMicro[20];
    char empresaMicro[20];
    char tipoMicro[20];
    float precio;

    if (cargarDescripcionDestino(destinos, tamD, unViaje.idDestino, descMicro, &precio) == 1 &&
            cargarEmpresaMicro(lista, tam, empresas, tamE, unViaje.idMicro, empresaMicro) ==1 &&
            cargarTipoMicro(lista, tam, tipos, tamT, unViaje.idMicro, tipoMicro)== 1)
    {
        printf(" %d            %d            %10s      %10s     %10s         $%.2f           %02d/%02d/%04d\n",
               unViaje.id,
               unViaje.idMicro,
               empresaMicro,
               tipoMicro,
               descMicro,
               precio,
               unViaje.fecha.dia,
               unViaje.fecha.mes,
               unViaje.fecha.anio );
    }
}


int mostrarViajes( eViaje viajes[], int tamV ,eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int checkStatus = 0;
    int flag = 1;

    if( viajes != NULL && tamV > 0 &&lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("                                            **** LISTA DE VIAJES****     \n");
        printf("\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf(" ID VIAJE        ID MICRO            EMPRESA          TIPO        DESCRIPCION        PRECIO               FECHA \n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam ; i++)
        {
            if(!viajes[i].isEmpty)
            {
                mostrarViaje(viajes[i], lista, tam, destinos, tamD, empresas, tamE, tipos, tamT);
                flag=0;
            }
        }
        if (flag)
        {
            printf("No hay trabajos para mostrar.\n");

        }
        checkStatus = 1;

    }
    return checkStatus;
}


