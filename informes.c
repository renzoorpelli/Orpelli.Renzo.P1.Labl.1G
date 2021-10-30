#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "micros.h"
#include "empresas.h"
#include "tipo.h"
#include "destino.h"
#include "viaje.h"
#include "validarEntero.h"


int menuInformes()
{
    int opcion = 0;
    system("cls");
    printf("------------------------------\n");
    printf("    ***INFORMES MICROS***   \n");
    printf("------------------------------\n");
    printf("1- INFORMAR MICROS S/EMPRESA\n");
    printf("2- INFORMAR MICROS S/TIPO\n");
    printf("3- INFORME PROMEDIO MICROS VIP\n");
    printf("4- INFORMAR MICROS LISTADOS POR EMPRESA\n");
    printf("5- INFORMAR EMPRESAS QUE PUEDEN TRANSPORTAR MAS PASAJEROS\n");
    printf("6. INFORME EMPRESAS CON MENOS MICROS\n");
    printf("7- INFORME VIAJES SEGUN MICROS\n");
    printf("8- INFORMAR IMPORTE A PAGAR\n");
    printf("9- \n");
    printf("10- \n");
    printf("11- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


int informeMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int idEmpresa;

    if (lista != NULL && tam > 0 && empresas !=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 )
    {
        system("cls");
        printf("                            **** LISTA DE  MICROS SEGUN EMPRESA****     \n");
        printf("-------------------------------------------------------------------------------------\n");


        mostrarEmpresas(empresas, tamE);
        validarEntero(&idEmpresa,"Ingrese el id EMPRESA del MICRO \n", "ERRROR...Ingrese el id EMPRESA del MICRO \n", 1000, 1003, 10);
        mostrarMicrosEmpresa(idEmpresa, lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        checkStatus = 1;
    }
    return checkStatus;

}


int mostrarMicrosEmpresa(int idEmpresa, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,  eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int flag = 1;
    char descEpresa[20];

    if (lista != NULL && tam > 0 && empresas !=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 )
    {
        system("cls");
        printf("                            **** LISTA DE  MICROS SEGUN EMPRESA****     \n");
        printf("------------------------------------------------------------------------------------------------\n");

        printf(" ID                 EMPRESA           TIPO         NOMBRE CHOFER     SEXO CHOFER       CAPACIDAD\n");
        printf("------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam ; i++)
        {
            if(!lista[i].isEmpty && lista[i].idEmpresa == idEmpresa)
            {
                mostrarMicro(lista[i], empresas, tamE, tipos, tamT, choferes, tamChof);
                flag=0;
            }

        }
        if(flag)
        {
            cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descEpresa);
            printf("No hay micros en %s\n", descEpresa);
        }
        checkStatus = 1;
    }
    return checkStatus;
}


int informeMicrosTipo(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int idTipo;

    if (lista != NULL && tam > 0 && empresas !=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 )
    {
        system("cls");
        printf("                            **** LISTA DE  MICROS SEGUN TIPO****     \n");
        printf("-------------------------------------------------------------------------------------\n");


        mostrarTipo(tipos, tamT);
        validarEntero(&idTipo,"Ingrese el id TIPO del MICRO \n", "ERRROR...Ingrese el id TIPO del MICRO \n", 5000, 5003, 10);
        mostrarMicrosTipo(idTipo, lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        checkStatus = 1;
    }
    return checkStatus;

}


int mostrarMicrosTipo(int idTipo, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,  eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int flag = 1;
    char descTipo[20];

    if (lista != NULL && tam > 0 && empresas !=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 )
    {
        system("cls");
        printf("                            **** LISTA DE  MICROS SEGUN TIPO****     \n");
        printf("------------------------------------------------------------------------------------------------\n");

        printf(" ID                 EMPRESA           TIPO         NOMBRE CHOFER     SEXO CHOFER       CAPACIDAD\n");
        printf("------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam ; i++)
        {
            if(!lista[i].isEmpty && lista[i].idTipo == idTipo)
            {
                mostrarMicro(lista[i], empresas, tamE, tipos, tamT, choferes, tamChof);
                flag=0;
            }

        }
        if(flag)
        {
            cargarDescripcionTipo(tipos, tamT, idTipo, descTipo);
            printf("No hay micros en %s\n", descTipo);
        }
        checkStatus = 1;
    }
    return checkStatus;
}

int informePromedioMicrosVip(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int contadorVip = 0;
    int contadorTotal = 0;
    float promedioTotal;

    if (lista != NULL && tam > 0 && empresas!=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 && choferes != NULL && tamChof > 0)
    {
        for (int i = 0; i < tam ; i++)
        {
            if (lista[i].idTipo == 5003)
            {
                contadorVip++;
            }
        }

        for (int j=0; j < tam; j++ )
        {
            if(!lista[j].isEmpty && lista[j].idTipo)
            {
                contadorTotal++;

            }
        }
        promedioTotal = ((float)contadorVip/contadorTotal)*100;

        system("cls");
        printf("----------------------PROMEDIOS--------------------\n\n");
        printf("La cantidad de micros de tipo vip es %d y su promedio es de %.2f\n", contadorVip, promedioTotal);
        printf("-------------------------------------------------------------\n");
        todoOk = 1;
    }
    return todoOk;
}

int informarMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0 && empresas!=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 && choferes != NULL && tamChof > 0)
    {
        system("cls");
        printf("               ***MICROS SEGUN EMPRESAS***\n");
        for (int i = 0; i < tamE; i++)
        {
            printf("LOCALIDAD: %10s\n", empresas[i].descripcion);
            mostrarMicrosEmpresaID(lista, tam, empresas, tamE, tipos, tamT , choferes, tamChof, empresas[i].id);
            printf("------------------------------------------------------------------------------------------\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosEmpresaID(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof ,int idEmrepesa)
{
    int todoOk = 0;
    int flag = 1;
    char descEmpresa[20];
    if (lista != NULL && tam > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        printf("                            **** LISTA DE  MICROS SEGUN EMPRESA****     \n");
        printf("------------------------------------------------------------------------------------------------\n");

        printf(" ID                 EMPRESA           TIPO         NOMBRE CHOFER     SEXO CHOFER       CAPACIDAD\n");
        printf("------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idEmpresa == idEmrepesa)
            {
                mostrarMicro(lista[i], empresas, tamE, tipos, tamT, choferes, tamChof);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionEmpresa(empresas, tamE, idEmrepesa, descEmpresa);
            printf("   No hay notebooks de la marca :  %s.\n", descEmpresa);
        }
        todoOk = 1;
    }
    return todoOk;

}


int informeEmpresaMasPasajeros(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int contadores[4]= {0,0,0,0};
    int mayor;
    if (lista != NULL && tam > 0 && empresas!=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 && choferes != NULL && tamChof > 0)
    {
        system("cls");
        printf("                   **** EMPRESA MAS PASAJEROS****     \n");

        for (int i =0; i < tamE; i++)
        {
            for (int j=0; j<tam; j++)
            {
                if(!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id)
                {
                    contadores[j]++;
                }
            }
        }

        for (int i = 0; i<tamE; i++)
        {
            if (i==0|| contadores[i] > mayor)
            {
                mayor = contadores[i];
            }
        }

        for (int i = 0; i<tamE; i++)
        {
            if (contadores[i] == mayor)
            {
                printf("las EMPRESAS CON MAS CAPACIDADES SON  %s\n", empresas[i].descripcion);
            }
        }
        printf("CON LA CANTIDAD DE %d micros.\n", mayor);
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

int informeEmpresaMenosPasajeros(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int contadores[4]= {0,0,0,0};
    int menor= 0;
    if (lista != NULL && tam > 0 && empresas!=NULL &&tamE > 0 && tipos!=NULL && tamT > 0 && choferes != NULL && tamChof > 0)
    {
        system("cls");
        printf("                   **** EMPRESA MAS PASAJEROS****     \n");


        for (int i = 0; i < tamE; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if ( !lista[i].isEmpty && lista[i].idEmpresa == empresas[j].id)
                {
                    contadores[j]++;
                }
            }
        }

        for (int i = 0; i<tamE; i++)
        {
            if (i==0|| contadores[i] < menor)
            {
                menor = contadores[i];
            }
        }

        for (int i = 0; i<tamE; i++)
        {
            if (contadores[i] == menor)
            {
                printf("las EMPRESAS CON MENOS CAPACIDADES SON  %s\n", empresas[i].descripcion);
            }
        }
        printf("CON LA CANTIDAD DE %d MICROS.\n", menor);

        todoOk = 1;
    }
    return todoOk;
}



int informarViajesMicro(eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 0;
    int IdMicros;

    if(viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && destinos != NULL && tamD > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        mostrarMicros(lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        validarEntero(&IdMicros,"Ingrese ID MICROS:\n", "ERROR Ingrese ID MICROS:\n", 10000, 10010, 10);
        informarViajes(IdMicros, viajes, tamV, lista, tam, destinos, tamD, empresas, tamE, tipos, tamT, choferes, tamChof);
        todoOk = 1;
    }

    return todoOk;
}

int informarViajes(int IdMicros,eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int flag =1;
    char descDestino[20];
    float precio;

    if(viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && destinos != NULL && tamD > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("                            **** LISTA DE  VIAJES MICRO****     \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");

        printf(" ID VIAJE          ID MICRO              EMPRESA               TIPO             DESTINO                FECHA\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tam ; i++)
        {
            if(!viajes[i].isEmpty && viajes[i].idMicro == IdMicros)
            {
                mostrarViaje(viajes[i], lista, tam, destinos, tamD, empresas, tamE, tipos, tamT);
                flag = 0;
            }

        }
        if(flag)
        {
            cargarDescripcionDestino(destinos, tamD, destinos->id, descDestino, &precio);
            printf("No hay Destinos %s\n", descDestino);
        }

        checkStatus = 1;
    }
    return checkStatus;
}



int informarImporteMicro(eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int todoOk = 1;
    int idMicros;
    if(viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && destinos != NULL && tamD > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("                            **** IMPORTES MICRO POR VIAJES****     \n");
        printf("-------------------------------------------------------------------------------------\n");

        mostrarMicros(lista, tam, empresas, tamE, tipos, tamT, choferes, tamChof);
        validarEntero(&idMicros,"Ingrese ID MICROS:\n", "ERROR Ingrese ID MICROS:\n", 10000, 10010, 10);
        informeImporte(idMicros, viajes, tamV, lista, tam, destinos, tamD, empresas, tamE, tipos, tamT,choferes, tamChof);

    }

    return todoOk;
}

int informeImporte(int idMicro,eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof)
{
    int checkStatus = 0;
    int flag =1;
    int acumImporte;

    if(viajes != NULL && tamV > 0 && lista != NULL && tam > 0 && destinos != NULL && tamD > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("                            **** LISTA DE  DESTINOS MICRO****     \n");
        printf("-------------------------------------------------------------------------------------\n");

        printf(" ID VIAJE          ID MICRO              EMPRESA               TIPO             DESTINO                FECHA\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < tamV ; i++)
        {
            if(!viajes[i].isEmpty && viajes[i].idMicro == idMicro)
            {
                mostrarViaje(viajes[i], lista, tam, destinos, tamD, empresas, tamE, tipos, tamT);
                flag = 0;
            }
        }

        for (int i = 0; i < tam ; i++)
        {
            for (int j = 0; j < tamV; j++)
            {
                for(int d =0; d < tamD; d++)
                {
                    if(!lista[i].isEmpty && !viajes[j].isEmpty && lista[i].id == idMicro && lista[i].id == viajes[j].idMicro && viajes[j].idDestino == destinos[d].id)
                    {
                        acumImporte += destinos[d].precio;

                    }

                }
            }
        }
        printf("El importe a pagar por el MICRO  %d es de %d\n", idMicro, acumImporte);


        if(flag)
        {
            printf("No hay importe para  %d\n", idMicro);
        }

        checkStatus = 1;
    }
    return checkStatus;
}



