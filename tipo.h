#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED
/** \brief funcion encargada de mostrar todos los tipos de viajes disponibles al usuario
 *
 * \param tipos[]
 * \param tamT
 * \return 0 si hay error 1 si esta todo bien
 *
 */
int mostrarTipo( eTipo tipos[], int tamT);

/** \brief busca que el tipo ingresada por el cliente exista
 *
 * \param id
 * \param tipos[]
 * \param tamT
 * \return 0 si hay error 1 si esta todo bien
 *
 */

int validarIdTipo( int id, eTipo tipos[], int tamT);

/** \brief se encarga de cargar toda la informacion de los tipos de viaje para informarle al cliente
 *
 * \param tipos[]
 * \param tamT
 * \param  idTipo
 * \param descripcion[]
 * \return -1 si hay error 1 si esta todo bien
 *
 */

int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo, char descripcion[]);
