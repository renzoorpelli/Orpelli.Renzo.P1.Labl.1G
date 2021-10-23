#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


int mostrarTipo( eTipo tipos[], int tamT )
{
    int todoOk = 0;
    if (tipos != NULL && tamT > 0 )
    {
        printf("           *** TIPO PASAJE***\n");
        printf("--------------------------------------\n");
        printf("    ID                  Descripcion\n");
        printf("--------------------------------------\n");
        for (int i = 0; i < tamT; i++)
        {
            printf("   %d             %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarIdTipo( int id, eTipo tipos[], int tamT )
{
    int esValido = 0;
    if (tipos != NULL && tamT > 0)
    {
        for (int i = 0; i < tamT; i++)
        {
            if (id == tipos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (tipos != NULL && tamT > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamT; i++)
        {
            if (tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
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

