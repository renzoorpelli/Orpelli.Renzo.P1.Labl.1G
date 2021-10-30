#include "chofer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostrarChoferes( eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    if (choferes != NULL && tamChof > 0 )
    {
        printf("           *** CHOFERES MICROS***\n");
        printf("----------------------------------------------\n");
        printf("    Id                  Nombre            Sexo\n");
        printf("---------------------------------------------- \n");
        for (int i = 0; i < tamChof; i++)
        {
            printf("   %d             %10s          %c\n", choferes[i].id, choferes[i].nombre, choferes[i].sexo);
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarIdChofer(int id,eChofer choferes[], int tamChof )
{
    int esValido = 0;
    if (choferes != NULL && tamChof > 0)
    {
        for (int i = 0; i < tamChof; i++)
        {
            if (id == choferes[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarNombreChofer(eChofer choferes[], int tamChof, int idChofer, char nombre[], char* sexo)
{
    int todoOk = 0;
    int flag = 1;
    if (choferes != NULL && tamChof > 0 && nombre != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamChof; i++)
        {
            if (choferes[i].id == idChofer)
            {
                strcpy(nombre, choferes[i].nombre);
                *sexo = choferes[i].sexo;
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

