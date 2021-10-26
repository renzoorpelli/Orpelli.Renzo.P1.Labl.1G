#ifndef EMPRESAS_H_INCLUDED
#define EMPRESAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eEmpresa;

#endif // EMPRESAS_H_INCLUDED

/** \brief funcion encargada de mostrar todas las empresas disponibles al usuario
 *
 * \param empresas[]
 * \param tamE
 * \return 0 si hay error 1 si esta todo bien
 *
 */

int mostrarEmpresas( eEmpresa empresas[], int tamE);

/** \brief busca que la empresa ingresada por el cliente exista
 *
 * \param id
 * \param empresas[]
 * \param tamE
 * \return 0 si hay error 1 si esta todo bien
 *
 */

int validarIdEmpresa( int id, eEmpresa empresas[], int tamE);

/** \brief se encarga de cargar toda la informacion de las empresas para informarle al cliente
 *
 * \param empresas[]
 * \param tamE
 * \param  idEmpresa
 * \param descripcion[]
 * \return -1 si hay error 1 si esta todo bien
 *
 */

int cargarDescripcionEmpresa( eEmpresa empresas[], int tamE, int idEmpresa, char descripcion[] );
