#ifndef EMPRESAS_H_INCLUDED
#define EMPRESAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eEmpresa;

#endif // EMPRESAS_H_INCLUDED
int mostrarEmpresas( eEmpresa empresas[], int tamE);

int validarIdEmpresa( int id, eEmpresa empresas[], int tamE);

int cargarDescripcionEmpresa( eEmpresa empresas[], int tamE, int idEmpresa, char descripcion[] );
