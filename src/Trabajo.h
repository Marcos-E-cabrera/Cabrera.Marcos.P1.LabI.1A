#include "fecha.h"
#include "notebook.h"
#include "servicio.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
    int id;
    int idNotebbok;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

int inicializarTrabajo(eTrabajo vec[], int tam);

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);

int altaTrabajo(eTrabajo trabajo[], int tamTrabajo, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio,  eMarca marcas[], int tamMarcas ,eTipo tipos[], int tamTipo, int* pIdTrabajo);

int listarTrabajo(eTrabajo trabajo[], int tamTrabajo, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio, eMarca marcas[], int tamMarcas);
