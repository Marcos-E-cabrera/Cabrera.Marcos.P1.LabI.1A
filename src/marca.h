#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif /* MARCA_H_ */

int listarMarca(eMarca marca[], int tamMarcas);

int cargarDescripcionMarca(eMarca marca[], int tamMarcas, int id, char descripcion[]);

int buscarMarca(eMarca marca[], int tamMarcas, int id, int* pIndice);

int validarMarca(eMarca marca[], int tamMarcas, int id);
