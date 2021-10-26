#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "micros.h"
#include "viaje.h"

/** \brief funcion que hardcodea valores para testing, opcion 4 menu
 *
 * \param lista[]
 * \param tam lista
 * \param cantidad de hardcodeos
 * \param pid
 * \return contador, ilteraciones por el for
 *
 */

int hardcodeaMicros(eMicro lista[], int tam, int cant, int* pId);
/** \brief funcion que hardcodea valores para testing, opcion 9 menu
 *
 * \param viaejs[]
 * \param tam tamV
 * \param cantidad de hardcodeos
 * \param pid
 * \return contador, ilteraciones por el for
 *
 */
int hardcodeaViajes(eViaje viajes[], int tamV, int cant, int* pId);
#endif // DATAWAREHOUSE_H_INCLUDED
