#ifndef MICROS_H_INCLUDED
#define MICROS_H_INCLUDED
#include "empresas.h"
#include "tipo.h"
typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;

}eMicro;

#endif // MICROS_H_INCLUDED

/** \brief muestra el menu de opciones
 *
 * \return la opcion elegida por el usuario
 *
 */

int menu();

/** \brief inicializa el vector de lista par aniadir un  nuevo micro
 *
 * \param lista[]
 * \param tam
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int inicializarMicros(eMicro lista[], int tam);

/** \brief busca una posicion libre para el vector
 *
 * \param lista[]
 * \param tam
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int buscarLibre(eMicro lista[], int tam);
/** \brief funcion encargada de dar el alta de un micro asignandole un id
 *
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

int altaMicros(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pId);
/** \brief funcion encargada de mostrar un micro con sus caracteristicas
 *
 * \param lista
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return funcion void
 *
 */

void mostrarMicro( eMicro lista, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
/** \brief funcion encargada de mostrar TODOS los  micros con sus caracteristicas
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int mostrarMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
/** \brief funcion encargada de ordenar los micros segun empresa, y si estas son iguales ordena por capacidad capacidad
 *
 * \param lista[]
 * \param tam
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int ordenarMicros(eMicro lista[], int tam);
/** \brief funcion encargada de realizar la baja logica del sistema
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int bajaMicroSistema(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
/** \brief funcion encargada de buscar un micro por el id brindado por el programa
 *
 * \param lista[]
 * \param tam
 * \param id
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int buscarMicroId( eMicro lista[], int tam, int Id );
/** \brief funcion encargada de modificar los datos indicados por las consignas tipo y capacidad
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int modificarMicro(eMicro lista[], int tam, eEmpresa empresas[], int tamE,eTipo tipos[], int tamT);
/** \brief funcion encargada de  brindar el menu de opciones y pedir confirmaciones sobre los cambios a realizar, en este caso recibe parametros porque necesita mostrar la descripcion completa del micro
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int menuModificar( eMicro lista[], int tam, int indice, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT );
/** \brief funcion encargada de cargar el nombre de la empresa para que el programa sea mas facil de entender para el usuario
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */

int cargarEmpresaMicro( eMicro lista[], int tam, eEmpresa empresas[], int tamE, int idMicro, char empresa[]);


/** \brief funcion encargada de cargar el el tipo de micro para que el programa sea mas facil de entender para el usuario
 *
 * \param lista[]
 * \param tam
 * \param empresas[]
 * \param tamE
 * \param tipos[]
 * \param tamT
 * \return 0 si hubo error 1 si esta todo bien
 *
 */
int cargarTipoMicro( eMicro lista[], int tam, eTipo tipos[], int tamT, int idMicro, char tipo[]);
