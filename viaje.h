#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include "fecha.h"
#include "micros.h"
#include "empresas.h"
#include "destino.h"
#include "tipo.h"
typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;

#endif // VIAJE_H_INCLUDED

/** \brief inicializa el vector de viaje par aniadir un  nuevo micro
 *
 * \param viajes[]
 * \param tamV
 * \return 0 si hubo error 1 si esta todo bien
 *
 */
int inicializarViaje(eViaje viajes[], int tamV);
/** \brief busca una posicion libre para la carga de un nuevo viajes
 *
 * \param viajes[]
 * \param tamV
 * \return 0 si hubo error 1 si esta todo bien
 *
 */
int buscarLibreViaje(eViaje viajes[], int tamV);
/** \brief funcion encargada de dar el alta de un viaje asignandole un id
 *
 * \param viajes[]
 * \param tamV
 * \param micros[] es el mismo que lista
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \param pId
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int altaViaje(eViaje viajes[], int tamV,eMicro lista[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD, eChofer choferes[], int tamChof, int* pIdViajes);
/** \brief funcion encargada de mostrar un viaje con sus caracteristicas
 *
 * \param unViaje
 * \param lista
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return funcion void
 *
 */

void mostrarViaje( eViaje unViaje, eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);

/** \brief funcion encargada de mostrar todos los viajes y sus caracteristicas
 *
 * \param viajes[]
 * \param tamV
 * \param micros[] es el mismo que lista
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \param pId
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int mostrarViajes( eViaje viajes[], int tamV ,eMicro lista[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
