#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/**
 * VALIDADOR DE FECHAS 1970 A 2022
 * @param fecha PUNTERO
 * @return RETORNA 1 SI ESTA BIEN, 0 SI ESTA MAL
 */
int validarfecha(eFecha *fecha);
