#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "micros.h"
#include "empresas.h"
#include "tipo.h"
#include "validarEntero.h"


int menu()
{
    int opcion = 0;
    system("cls");
    printf("------------------------------\n");
    printf("    ***EMPRESA MICROS***   \n");
    printf("------------------------------\n");
    printf("1- ALTA MICRO\n");
    printf("2- MODIFICAR MICRO\n");
    printf("3- BAJA MICRO\n");
    printf("4- LISTAR MICROS\n");
    printf("5- LISTAR EMPRESAS\n");
    printf("6. LISTAR TIPOS\n");
    printf("7- LISTAR DESTINOS\n");
    printf("8- ALTA VIAJES\n");
    printf("9- LISTAR VIAJES\n");
    printf("10- LISTAR CHOFERES\n");
    printf("11- MOSTRAR INFORMES\n");
    printf("12- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


int inicializarMicros(eMicro lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return todoOk;
}


int buscarLibre(eMicro lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pId)
{
    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if(lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0 && pId != NULL)
    {
        system("cls");
        printf("            ***ALTA MICROS***     \n\n");
        printf("------------------------------------\n");
        indice = buscarLibre(lista, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMicro.id = *pId;
            (*pId)++;

            mostrarEmpresas(empresas, tamE);
            printf("---------------------------\n");
            printf("Ingrese id la Empresa: \n");
            scanf("%d", &auxMicro.idEmpresa);
            while ( !validarIdEmpresa(auxMicro.idEmpresa, empresas, tamE) )
            {
                printf("ERROR...Ingrese id marca:\n");
                scanf("%d", &auxMicro.idEmpresa);
            }
            system("cls");
            mostrarTipo(tipos, tamT);
            printf("---------------------------\n");
            printf("Ingrese el id del tipo de viaje: \n");
            scanf("%d", &auxMicro.idTipo);
            while(!validarIdTipo(auxMicro.idTipo, tipos, tamT))
            {
                printf("ERROR...Ingrese id del tipo de viaje:\n");
                scanf("%d", &auxMicro.idTipo);
            }
            system("cls");
            printf("---------------------------\n");
            validarEntero(&auxMicro.capacidad, "Ingrese la capacidad del micro: NO DEBE PASAR 50 PERSONAS \n", "ERROR...Ingrese la capacidad del micro: NO DEBE PASAR 50 PERSONAS \n", 5, 50, 10);

            auxMicro.isEmpty = 0;
            lista[indice] = auxMicro;
            todoOk = 1;

        }

    }
    return todoOk;
}


void mostrarMicro( eMicro lista, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    char descEmpresa[20];
    char descTipo[20];
    char nombreChofer[20];
    char sexoChofer;

    if ( ( cargarDescripcionEmpresa( empresas, tamE, lista.idEmpresa, descEmpresa ) == 1 ) &&
            ( cargarDescripcionTipo( tipos, tamT, lista.idTipo, descTipo ) == 1 ) &&
        (cargarNombreChofer(choferes, tamChof, lista.idChofer, nombreChofer, &sexoChofer)== 1))
    {
        printf("  %d          %10s      %10s       %10s             %c                     %d \n",
               lista.id,
               descEmpresa,
               descTipo,
               nombreChofer,
               sexoChofer,
               lista.capacidad );
    }
}

int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int flag = 1;

    if(lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("               **** LISTA DE MICROS****     \n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf(" ID             EMPRESA           TIPO              NOMBRE CHOFER       SEXO CHOFER         CAPACIDAD\n");
        printf("-----------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarMicro(lista[i], empresas, tamE, tipos, tamT, choferes, tamChof);
                flag = 0;
            }
        }

        if (flag)
        {
            printf("No hay autos para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarMicros(eMicro lista[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if (lista != NULL && tam >0)
    {
        for (int i = 0; i < tam -1; i++)
        {
            for (int j = i+1; j < tam; j++)
            {
                if( lista[i].idEmpresa < lista[j].idEmpresa ||
                        (lista[i].idEmpresa == lista[j].idEmpresa &&
                         lista[i].capacidad > lista[j].capacidad))
                {
                    auxMicro = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMicro;
                }
            }
        }
    }

    return todoOk;
}
int bajaMicroSistema(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaBaja;

    if(lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** BAJA DE MICROS DEL SISTEMA *** \n\n");
        mostrarMicros(lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id del Micro: \n");
        scanf("%d", &id);

        indice = buscarMicroId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMicro(lista[indice], empresas, tamE, tipos, tamT, choferes, tamChof );
            printf("Confirma baja del sistema? S o N: \n");
            fflush(stdin);
            scanf("%c", &confirmaBaja);
            confirmaBaja = tolower(confirmaBaja);
            if (confirmaBaja == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }

        }
    }
    return todoOk;
}


int buscarMicroId( eMicro lista[], int tam, int Id )
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].id == Id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int modificarMicro(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmaCambio = 's';
    char seguir = 's';
    char salir;
    eMicro auxMicro;
    if(lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** MODIFICACION DE MICROS DEL SISTEMA *** \n\n");
        mostrarMicros(lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        printf("------------------------------------------------------------\n");
        printf("Ingrese id del Micro: ");
        scanf("%d", &id);

        indice = buscarMicroId(lista, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch(menuModificar(lista,tam, indice, empresas, tamE, tipos, tamT, choferes, tamChof))
                {
                case 1:
                    mostrarTipo(tipos, tamT);
                    printf("*** MODIFICAR TIPO MICRO ***: \n");
                    printf("Ingrese nuevo id del tipo de viaje:\n");
                    scanf("%d", &auxMicro.idTipo);
                    while(!validarIdTipo(auxMicro.idTipo, tipos, tamT))
                    {
                        printf("ERROR...Ingrese id del tipo de viaje:\n");
                        scanf("%d", &auxMicro.idTipo);
                    }
                    printf("Confirma el cambio? S o N \n");
                    fflush(stdin);
                    scanf("%c", &confirmaCambio);
                    confirmaCambio = tolower(confirmaCambio);
                    while(confirmaCambio != 's' && confirmaCambio !='n')
                    {
                        printf("Confirma el cambio? S o N \n");
                        fflush(stdin);
                        scanf("%c", &confirmaCambio);
                        confirmaCambio = tolower(confirmaCambio);
                    }
                    if( confirmaCambio == 's')
                    {
                        lista[indice].idTipo = auxMicro.idTipo;
                    }
                    else
                    {
                        printf("mofificacion cancelada por el usuario\n");
                    }
                    break;
                case 2:
                    printf("*** MODIFICAR CAPACIDAD MICRO ***: \n");
                    validarEntero(&auxMicro.capacidad,"Ingrese la nueva capaacidad del micro:\n", "ERROR...Ingrese la nueva capaacidad del micro:\n", 5, 50, 10);
                    fflush(stdin);
                    printf("Confirma el cambio? S o N \n");
                    scanf("%c", &confirmaCambio);
                    confirmaCambio = tolower(confirmaCambio);
                    if( confirmaCambio == 's')
                    {
                        lista[indice].capacidad = auxMicro.capacidad;
                    }
                    else
                    {
                        printf("mofificacion cancelada por el usuario\n");
                    }
                    break;
                case 3:
                    printf("Usted eligio salir\n");
                    printf("Esta seguro que desea salir? S o N\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = tolower(salir);
                    while ( salir != 's' && salir != 'n')
                    {
                        printf("Esta seguro que desea salir? S o N\n");
                        fflush(stdin);
                        scanf("%c", &salir);
                        salir = tolower(salir);
                    }
                    if (salir == 's')
                    {
                        seguir = 'n';
                    }
                    break;
                default:
                    printf("OPCION INVALIDA\n");
                    break;
                }

            }
            while(seguir == 's');
        }
    }

    return todoOk;
}

int menuModificar( eMicro lista[], int tam, int indice, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int opcion = 0;
    system("cls");
    printf("------------------------------------------------------------\n");
    mostrarMicro(lista[indice], empresas, tamE, tipos, tamT, choferes, tamChof);
    printf("------------------------------------------------------------\n");
    printf("1- Editar tipo\n");
    printf("2- Editar Capacidad\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int cargarEmpresaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, int idMicro, char empresa[])
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && empresa != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMicro)
            {
                cargarDescripcionEmpresa(empresas, tamE, lista[i].idEmpresa, descripcion);
                strcpy(empresa, descripcion);
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

int cargarTipoMicro( eMicro lista[], int tam, eTipo tipos[], int tamT, int idMicro, char tipo[])
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && tipo != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMicro)
            {
                cargarDescripcionTipo(tipos, tamT, lista[i].idTipo, descripcion);
                strcpy(tipo, descripcion);
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
