#ifndef VALIDARFLOTANTE_H_INCLUDED
#define VALIDARFLOTANTE_H_INCLUDED


int getIntFloat (float* pResultado);

int myGetsFloat(char* cadena, int longitud);


int validarEnteroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int esNumericoFlotante(char str[]);

#endif // VALIDARFLOTANTE_H_INCLUDED
