#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"

int inicializarTrabajos(eTrabajo vec[], int tam){
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
	int indice = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL )
    {
    	*pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty ) // isEmpty == 1
            {
            	*pIndex = i;
                break;
            }
        }
        indice = 1;
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajo[], int tamT, eNotebook notebook[], int tamN,eMarca marcas[], int tamM, eTipo tipos[], int tamTp, eServicio servicio[], int tamS, eCliente cliente[], int TamCliente, int* pIdTrabajo)
{
	int valFecha = 0;
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(trabajo != NULL && marcas != NULL && tipos != NULL && servicio != NULL && notebook != NULL && pIdTrabajo != NULL && tamT > 0 && tamN > 0 && tamM && tamTp > 0 && tamS > 0)
    {
    	if(buscarTrabajoLibre(trabajo, tamT, &indice))
    	{
    		if(indice == - 1){
    			printf(" | * No hay lugar en el sistema * |\n");
    		}
    		else
    		{
    			listarNotebook(notebook, tamN, tipos, marcas, cliente);
    			printf(" |Ingrese id notebook: ");
    			scanf("%d", &nuevoTrabajo.idNotebook);
    			buscarNotebook(notebook, tamN, nuevoTrabajo.idNotebook, &indice);

    			while( indice == -1){
    				printf(" |Notebook invalido. Ingrese id notebook: ");
    				scanf("%d", &nuevoTrabajo.idNotebook);
    				buscarNotebook(notebook, tamN, nuevoTrabajo.idNotebook, &indice);
    			}

    			listarServicio(servicio, tamS);
    			printf(" |Ingrese id servicio: ");
    			scanf("%d", &nuevoTrabajo.idServicio);

    			while( !validarServicio(servicio, tamS, nuevoTrabajo.idServicio)){
    				printf(" |Servicio invalido. Ingrese id servicio: ");
    				scanf("%d", &nuevoTrabajo.idServicio);
    			}

    			printf(" |Ingrese Fecha dd/mm/aaaa: ");
    			scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    			valFecha = validarfecha(&fecha);

    			while(valFecha != 1)
    			{
    				printf(" |Error fecha %d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
    				printf(" |Reingrese Fecha dd/mm/aaaa: ");
    				fflush(stdin);
    				scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    				valFecha =validarfecha(&fecha);
    			}
    			nuevoTrabajo.fecha = fecha;

    			nuevoTrabajo.isEmpty = 0;
    			nuevoTrabajo.id = *pIdTrabajo;
    			*pIdTrabajo = *pIdTrabajo + 1;
    			trabajo[indice] = nuevoTrabajo;
    			todoOk = 1;
    		}
    	}
    	else
    	{
    		printf(" | * Ocurrio un problema con los parametros * |\n");
    	}
    }
    return todoOk;
}

int listarTrabajo(eTrabajo trabajo[], eNotebook notebook[], eServicio servicio[], int tamTrabajo)
{
	int todoOk = 0;
    int flag = 0;
    char descripcion[20];

    if(trabajo != NULL && notebook != NULL && servicio != NULL  && tamTrabajo > 0)
    {
        system("cls");
        printf("\n  __________________________________________________\n");
        printf(" |             *** LISTADO DE TRABAJO ***           |\n");
        printf(" |__________________________________________________|\n");
        printf(" |  ID  | ID  NOTEBOOK |    SERVICIO   |    FECHA   |\n");
        printf(" |--------------------------------------------------|\n");

        for(int i=0; i < tamTrabajo; i++)
        {
            if( !trabajo[i].isEmpty)
            {
                cargarDescripcionServicio(servicio, tamTrabajo, trabajo[i].idServicio, descripcion);
                printf(" |  %-4d|     %-5d    | %-14s| %02d/%02d/%02d |\n",
                		trabajo[i].id,
						trabajo[i].idNotebook,
        				descripcion,
						trabajo[i].fecha.dia,
						trabajo[i].fecha.mes,
						trabajo[i].fecha.anio);
                flag++;
            }
        }

        if(flag == 0)
        {
            printf("       No hay trabajo en el sistema\n");
        }
        printf(" |--------------------------------------------------|");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajo(eTrabajo vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eTrabajo impostores[] =
    {
 //      id, id notebook, idservicio, fecha, 0
        {0, 100, 20001, {21,4,2022}, 0},
		{0, 101, 20001, {13,4,2022}, 0},
		{0, 102, 20000, {22,5,2022}, 0},
		{0, 103, 20003, {15,5,2022}, 0},
		{0, 104, 20002, {12,5,2022}, 0},
		{0, 105, 20002, {17,5,2022}, 0},
		{0, 106, 20003, {24,5,2022}, 0},
		{0, 107, 20000, {20,5,2022}, 0},
		{0, 108, 20000, {20,5,2022}, 0},
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;
        }
        todoOk = 1;
    }
    return todoOk;
}
