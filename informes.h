#include "micros.h"
#include "empresas.h"
#include "tipo.h"
#include "destino.h"
#include "viaje.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();
//
int informeMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);

int mostrarMicrosEmpresa(int idEmpresa, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,  eChofer choferes[], int tamChof);
//
int informeMicrosTipo(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);

int mostrarMicrosTipo(int idTipo, eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,  eChofer choferes[], int tamChof);
//
int informePromedioMicrosVip(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);
//
int informarMicrosEmpresa(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);
//
int mostrarMicrosEmpresaID(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof ,int idEmrepesa);
//
int informeEmpresaMasPasajeros(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof);
//
int informeEmpresaMenosPasajeros(eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT,eChofer choferes[], int tamChof);
//
int informarViajesMicro(eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);
//
int informarViajes(int IdMicros,eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);
//
int informarImporteMicro(eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);
int informeImporte(int idMicro,eViaje viajes[], int tamV, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eChofer choferes[], int tamChof);


