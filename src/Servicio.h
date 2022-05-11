#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
} eServicio;

#endif /* SERVICIO_H_ */

int listarServicio(eServicio servicio[], int tam);
int buscarServicio(eServicio servicio[], int tam, int id, int* pIndice);
int validarServicio(eServicio servicio[], int tam, int id);
int cargarDescripcionServicio(eServicio servicio[], int tam, int id, char descripcion[]);
