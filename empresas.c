#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresas.h"

int mostrarEmpresas( eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    if (empresas != NULL && tamE > 0 )
    {
        printf("      *** LISTA EMPREASAS *** \n");
        printf("--------------------------- \n\n");
        printf("  ID         DESCRIPCION\n");
        printf("--------------------------- \n\n");
        for (int i = 0; i < tamE; i++)
        {
            printf("  %d       %10s\n", empresas[i].id, empresas[i].descripcion);
        }
        todoOk = 1;
    }

    return todoOk;
}


int validarIdEmpresa( int id, eEmpresa empresas[], int tamE)
{
    int esValido = 0;
    if (empresas != NULL && tamE > 0)
    {
        for (int i = 0; i < tamE; i++)
        {
            if (id == empresas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


int cargarDescripcionEmpresa( eEmpresa empresas[], int tamE, int idEmpresa, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (empresas != NULL && tamE > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamE; i++)
        {
            if (empresas[i].id == idEmpresa)
            {
                strcpy(descripcion, empresas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia marca con el id que le pasaron
        }
    }
    return todoOk;
}


