#include "fecha.h"
#include "notebook.h"
#include "servicio.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

int inicializarTrabajos(eTrabajo vec[], int tam);

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);

int altaTrabajo(eTrabajo trabajo[], int tamT, eNotebook notebook[], int tamN,eMarca marcas[], int tamM, eTipo tipos[], int tamTp, eServicio servicio[], int tamS, eCliente cliente[], int TamCliente, int* pIdTrabajo);

int listarTrabajo(eTrabajo trabajo[], eNotebook notebook[], eServicio servicio[], int tamTrabajo);

int hardcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pId);
