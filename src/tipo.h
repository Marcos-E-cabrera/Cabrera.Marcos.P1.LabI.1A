#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

#endif /* TIPO_H_ */

int listarTipos(eTipo tipos[], int tamTipos);
int cargarDescripcionTipo(eTipo tipos[], int tamTipos, int id, char descripcion[]);
int buscarTipo(eTipo tipos[], int tamTipos, int id, int* pIndice);
int validarTipo(eTipo tipos[], int tamTipos, int id);
