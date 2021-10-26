#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micros.h"
#include "empresas.h"
#include "tipo.h"
#include "destino.h"
#include "viaje.h"
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
    eViaje viajes[TAM_V];
    int defaultIdViajes = 20000;


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
        printf("Error al iniciar Micros\n");
    }

    hardcodeaMicros(lista, TAM, 4, &defaultIdMicro);
    hardcodeaViajes(viajes, TAM_V, 4, &defaultIdViajes);

    do
    {
        switch (menu())
        {
        case 1:
            if( !altaMicros(lista, TAM, empresas, TAM_E, tipos, TAM_T, &defaultIdMicro) )
            {
                printf("No se pudo realizar el alta con exito\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }

            break;
        case 2:
            if(!modificarMicro(lista, TAM, empresas, TAM_E, tipos, TAM_T))
            {
                printf("No se pudo llevar a cabo la modificacion de datos\n");
            }
            else
            {
                printf("Cambios realizados con exito\n");
            }
            break;
        case 3:
            if(!bajaMicroSistema(lista, TAM, empresas, TAM_E, tipos, TAM_T))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 4:
            system("cls");
            ordenarMicros(lista, TAM);
            if ( !mostrarMicros(lista, TAM, empresas, TAM_E, tipos, TAM_T) )
            {
                printf("No se pudo mostrar los Micros\n");
            }
            break;
        case 5:
            system("cls");
            if ( !mostrarEmpresas(empresas, TAM_E) )
            {
                printf("No se pudo mostrar las Empresas\n");
            }
            break;
        case 6:
            system("cls");
            if ( !mostrarTipo(tipos, TAM_T) )
            {
                printf("No se pudo mostrar los Tipos\n");
            }
            break;
        case 7:
            system("cls");

            if ( !mostrarDestinos(destinos, TAM_D) )
            {
                printf("No se pudo mostrar los destinos\n");
            }
            break;
         case 8:
            if(!altaViaje(viajes, TAM_V, lista, TAM,empresas, TAM_E,tipos ,TAM_T, destinos, TAM_D,&defaultIdViajes))
            {
                printf("Surgio un error al realizar el alta de Viaje\n");
            }
            else
            {
                printf("Alta Viaje exitosa\n");
            }
            break;
        case 9:
            if(!mostrarViajes(viajes, TAM_V ,lista, TAM, destinos, TAM_D,empresas, TAM_E, tipos, TAM_T))
            {
                printf("Surgio un error al mostrar loss Viajes\n");
            }
            else
            {
                printf("Usted esta viendo los Viajes\n");
            }
            break;

        case 10:
            printf("Esta seguro que quiere salir? S o N \n");
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
            printf("Opcion invalida\n");
        }
        system("pause");

    }
    while(seguir == 's');


    return 0;
}

