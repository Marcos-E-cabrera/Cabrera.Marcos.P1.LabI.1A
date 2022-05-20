#include "tipo.h"
#include "marca.h"

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idtipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif /* NOTEBOOK_H_ */

/**
 *  INICIALIZO LAS NOTEBOOK PARA SABER SI ESTAN VACIOS "ISEMPTY = 1"
 * @param vec ARRAY DE NOTEBOOK
 * @param tam TAMANIO DEL ARRAY
 * @return 1 SI ESTA BIEN, 0 SI ESTA MAL
 */
int inicializarNotebook(eNotebook vec[], int tam);

/**
 * BUSCA LAS NOTEBOOK QUE ESTEN VACIAS, SI ESTAN PASO SU POSICION AL PINDEX
 * @param vec ARRAY DE NOTEBOOK
 * @param tam TAMANIO DEL ARRAY
 * @param pIndex DIRECCION DE LA NOTEBOOK
 * @return SI ENCONTRO UNA POSICION MANDA 1, SI NO MANDA -1
 */
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);

///------------ AMB NOTEBOOK

/**
 * CARGO UNA NUEVA NOTEBOOK
 * @param vec ARRAY DE NOTEBOOK
 * @param tam TAMANIO DEL ARRAY
 * @param marcas ARRAY DE MARCAS
 * @param tamMarcas TAMANIO DEL ARRAY
 * @param tipos ARRAY DE TIPOS
 * @param tamTipo TAMANIO DEL ARRAY
 * @param pId DIRECCION DEL ID PRINCIPAL QUE ESTA EN EL MAIN DEFINE DONDE EMPIEZA EJ:1000
 * @return 1 - BIEN, 0 MAL
 */
int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipo, int* pId);

/**
 * ELIMINO UNA NOTEBOOK YA INGRESADA
 * @param vec ARRAY DE NOTEBOOK
 * @param tam TAMANIO DEL ARRAY
 * @param tipos ARRAY DE TIPOS
 * @param marcas ARRAY DE MARCAS
 * @return 1 - BIEN, 0 MAL
 */
int bajaNotebook(eNotebook vec[], int tam, eTipo tipos[], eMarca marcas[]);

/**
 * MODIFICA UNA NOTEBOOK SELECCIONADA POR ID
 * @param noterbook ARRAY
 * @param tamNotebook TAMANIO DE ARRAY
 * @param tipos ARRAY
 * @param tamTipos TAMNIO DE ARRAY
 * @param marcas ARRAY
 * @param tamMarcas TAMANIO DE ARRAY
 * @return 1- BIEN, 0 -MAL
 */
int modificarNotebook(eNotebook noterbook[], int tamNotebook, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas);

/**
 * BUSCA UNA NOTEBOOK CARGADA POR ID Y MUESTRA SU DIRECCION
 * @param vec ARRAY DE NOTEBOOK
 * @param tam TAMANIO DE NOTEBOOK
 * @param id DE LA NOTEBOOK
 * @param pIndex DIRECCION DE MEMORIA DEL NOTEBOOK
 * @return 1- BIEN, 0 - MAL
 */
int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex);

/**
 * SUB MENU DE MODIFICACION
 * @return
 */
int menuModificar();

/// ----------- PARA PROBAR

/**
 * HARDCODEO LAS NOTEBOOKS
 * @param vec ARRAY NOTEBOOK
 * @param tam TAMANIO DEL ARRAY
 * @param cant CATIDAD DE NOTEBOOK
 * @param pId DE DONDE INICIA EL ID
 * @return 1- BIEN, 0- MAL
 */
int hardcodearNotebook(eNotebook vec[], int tam, int cant, int* pId);

///------------ MOSTRAR NOTEBOOK

/**
 * ORDENO LOS DATOS RECIBIDOS DEL NOTEBOOK
 * @param l ARRAY DE NOTEBOOK
 * @param tipos ARRAY DE TIPOS
 * @param marcas ARRAY DE MARCAS
 * @param tam TAMANIO DEL ARRAY NOTEBOOK
 * @return 1 - BIEN, 0 - MAL
 */
int mostrarNotebook(eNotebook l, eTipo tipos[], eMarca marcas[], int tam);

/**
 * MUSTRO EN UN CUADRO ORDENADO LOS NOTEBOOKS
 * @param list ARRAY NOTEBOOK
 * @param tam TAMANIO DEL ARRAY NOTEBOOK
 * @param tipo ARRAY TIPO
 * @param marcas ARRAY MASCAS
 * @return 1- BIEN, 0 - MAL
 */
int listarNotebook(eNotebook list[], int tam, eTipo tipo[], eMarca marcas[]);










