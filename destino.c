#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int mostrarDestinos(eDestino destinos[], int tamD)
{
    int todoOk = 0;
    if (destinos != NULL && tamD > 0 )
    {
        system("cls");
        printf("      *** SERVICIOS AUTOS *** \n");
        printf("---------------------------------------\n\n");
        printf("  ID         DESCRIPCION        PRECIO\n");
        printf("---------------------------------------\n\n");
        for (int i = 0; i < tamD; i++)
        {

            printf("  %d       %10s         $%.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarIdDestino(int id, eDestino destinos[], int tamD)
{
    int esValido = 0;
    if (destinos != NULL && tamD > 0)
    {
        for (int i = 0; i < tamD; i++)
        {
            if (id == destinos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionDestino( eDestino destinos[], int tamD, int idDestino, char descripcion[], float* precio)
{
    int todoOk = 0;
    int flag = 1;
    if (destinos != NULL && tamD > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamD; i++)
        {
            if (destinos[i].id == idDestino)
            {
                strcpy(descripcion, destinos[i].descripcion);
                *precio = destinos[i].precio;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
