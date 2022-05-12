#include "tipo.h"
#include "marca.h"

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct
{
    int id;
    char modelo[20]; // name
    int idMarca;
    int idtipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif /* NOTEBOOK_H_ */

///------------ AMB NOTEBOOK
int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipo, int* pId);
int bajaNotebook(eNotebook vec[], int tam, eTipo tipos[], eMarca marcas[]);
int modificarNotebook(eNotebook noterbook[], int tamNotebook, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas);

int inicializarNotebook(eNotebook vec[], int tam);
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);
int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex);
int hardcodearNotebook(eNotebook vec[], int tam, int cant, int* pId);
int menuModificar();

///--------------------------- MOSTRAR NOTEBOOK
int mostrarNotebook(eNotebook l, eTipo tipos[], eMarca marcas[], int tam);
int listarNotebook(eNotebook list[], int tam, eTipo tipo[], eMarca marcas[]);










