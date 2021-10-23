#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micros.h"
#include "empresas.h"
#include "tipo.h"
#include "destino.h"
#include "dataWarehouse.h"

#define TAM 10
#define TAM_E 4
#define TAM_T 4
#define TAM_D 4
#define TAM_V 10

int main()
{

    char seguir = 's';
    char salir;
    eMicro lista[TAM];
    int defaultIdMicro = 10000;
    int banderaInicio= 0;


    eEmpresa empresas[TAM_E] =
    {
        { 1000, "Plusmar" },
        { 1001, "Flechabus" },
        { 1002, "Tas" },
        { 1003, "El Rapido" }
    };

    eTipo tipos[TAM_T] =
    {
        { 5000, "Comun" },
        { 5001, "CocheCama" },
        { 5002, "Doble" },
        { 5003, "Vip" }
    };

    eDestino destinos[TAM_D] =
    {
        {20000, "Calafatee", 22250},
        {20001, "Bariloche", 103000},
        {20002, "Iguazu", 84400},
        {20003, "Mendoza", 95600}
    };


    if ( !inicializarMicros(lista, TAM) )
    {
        printf("Error al iniciar MICROS\n");
    }

    do
    {

        switch(menu())
        {
        case 1:
            if (banderaInicio== 0)
            {
                banderaInicio = 1;
                if( !altaMicros(lista, TAM, empresas, TAM_E, tipos, TAM_T, &defaultIdMicro) )
                {
                    printf("No se pudo realizar el alta con exito\n");
                }
                else
                {
                    printf("Alta exitosa\n");
                }
            }
            break;
        case 2:
            if(banderaInicio == 1)
            {

                if(!modificarMicro(lista, TAM, empresas, TAM_E, tipos, TAM_T))
                {
                    printf("No se pudo llevar a cabo la modificacion de datos\n");
                }
                else
                {
                    printf("Cambios realizados con exito\n");
                }
            }
            else
            {
                printf("Debe realizar un alta para poder hacer una modificacion en el sistema\n");
            }
            break;
        case 3:
            if (banderaInicio== 1)
            {
                if(!bajaMicroSistema(lista, TAM, empresas, TAM_E, tipos, TAM_T))
                {
                    printf("No se pudo realizar la baja\n");
                }
                else
                {
                    printf("Baja exitosa\n");
                }
            }
            else
            {
                printf("Debe realizar un alta para poder hacer una Baja en el sistema\n");
            }
            break;

        case 4:
            system("cls");
            if (!mostrarMicros(lista, TAM, empresas, TAM_E, tipos, TAM_T) )
            {
                printf("No se pudo mostrar los autos\n");
            }
            break;
        case 5:
            if ( !mostrarEmpresas(empresas, TAM_E) )
            {
                printf("No se pudo mostrar las Empresas\n");
            }
            break;
        case 6:
            if ( !mostrarTipo(tipos, TAM_T) )
            {
                printf("No se pudo mostrar los tipos\n");
            }
            break;
        case 7:
            if ( !mostrarDestinos(destinos, TAM_D) )
            {
                printf("No se pudo mostrar los servicios\n");
            }
            break;
        case 20:
            printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("opcion invalida \n");
            break;
        }
    }
    while(seguir == 's');




    return 0;
}




//ordenados por empresa y capacidad
