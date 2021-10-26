#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eDestino;

#endif // DESTINO_H_INCLUDED
/** \brief funcion encargada de mostrar todos los destinos disponibles al usuario
 *
 * \param destinos[]
 * \param tamD
 * \return 0 si hay error 1 si esta todo bien
 *
 */

int mostrarDestinos(eDestino destinos[], int tamD);
/** \brief busca que el destino ingresado por el cliente exista
 *
 * \param id
 * \param destinos[]
 * \param tamD
 * \return 0 si hay error 1 si esta todo bien
 *
 */

int validarIdDestino(int id, eDestino destinos[], int tamD);

/** \brief se encarga de cargar toda la informacion de los destinos para informarle al cliente
 *
 * \param destinos[]
 * \param tamD
 * \param  idDestino
 * \param descripcion[]
 * \param precio
 * \return -1 si hay error 1 si esta todo bien
 *
 */

int cargarDescripcionDestino( eDestino destinos[], int tamD, int idDestino, char descripcion[], float* precio);
