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

//// abm notebook
int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipo, int* pId);

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);

int inicializarNotebook(eNotebook vec[], int tam);

int mostrarNotebook(eNotebook l, eTipo tipos[], int tam);

int listarNotebook(eNotebook list[], int tam, eTipo tipo[]);

int modificarNotebook(eNotebook noterbook[], eTipo tipos[], int tam);

int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex);

int menuModificar();

int bajaNotebook(eNotebook vec[], int tam, eTipo tipos[]);

