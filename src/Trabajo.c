#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Trabajo.h"

int inicializarTrabajo(eTrabajo vec[], int tam)
{
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
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajo[], int tamTrabajo, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio,  eMarca marcas[], int tamMarcas ,eTipo tipos[], int tamTipo, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;
    int valFecha = 0;

    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(trabajo != NULL && marcas != NULL && notebook != NULL && tipos != NULL && pIdTrabajo != NULL && tamTrabajo > 0 && tamMarcas > 0 && tamNotebook > 0 && tamServicio > 0 && tamTipo > 0)
    {
    	system("cls");
    	printf("                    *** Alta Trabajo *** \n");
    	printf("-------------------------------------------------------------\n\n");

    	if(buscarTrabajoLibre(trabajo, tamTrabajo, &indice)){
    		if(indice == - 1){
    			printf("No hay lugar en el sistema\n");
    		}
    		else
    		{
    			listarNotebook(notebook, tamNotebook, tipos, marcas);
    			printf(" |Ingrese id notebook: ");
    			scanf("%d", &nuevoTrabajo.idNotebbok);
    			printf("\n");
    			buscarNotebook(notebook, tamNotebook, nuevoTrabajo.idNotebbok, &indice);

    			while( indice == -1){
    				printf("notebook invalido. Ingrese id notebook\n");
    				scanf("%d", &nuevoTrabajo.idNotebbok);
    				buscarNotebook(notebook, tamNotebook, nuevoTrabajo.idNotebbok, &indice);
    			}

    			listarServicio(servicio, tamServicio);
    			printf(" |Ingrese id servicio: ");
    			scanf("%d", &nuevoTrabajo.idServicio);
    			printf("\n");

    			while( !validarServicio(servicio, tamServicio, nuevoTrabajo.idServicio)){
    				printf("Comida invalido. Ingrese id comida\n");
    				scanf("%d", &nuevoTrabajo.idServicio);
    			}

    			printf("Ingrese Fecha dd/mm/aaaa: ");
    			scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    			valFecha = validarfecha(&fecha);

    			while(valFecha != 0)
    			{
    				printf("error fecha %d/%d/%d",fecha.dia,fecha.mes,fecha.anio);//TOMAMOS TRES VARIABLES JUNTAS
    				printf("Reingrese Fecha dd/mm/aaaa: ");
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
    		printf("Ocurrio un problema con los parametros\n");
    	}
    }
    return todoOk;
}

int listarTrabajo(eTrabajo trabajo[], int tamTrabajo, eNotebook notebook[], int tamNotebook, eServicio servicio[], int tamServicio, eMarca marcas[], int tamMarcas)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];
    if(trabajo != NULL && marcas != NULL && servicio != NULL && notebook != NULL  && tamTrabajo > 0 && tamMarcas > 0 && tamServicio > 0 && tamNotebook > 0)
    {
        system("cls");
        printf("      				*** Listado de trabajo ***\n\n");
        printf("  Id          Id Notebook       servicio 		    Fecha\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tamTrabajo; i++)
        {
            if( !trabajo[i].isEmpty )
            {
                cargarDescripcionServicio(servicio, tamServicio, trabajo[i].idServicio, descripcion);
                fflush(stdin);
                printf("   %d     %d      %10s       %02d/%02d/%02d\n", trabajo[i].id, trabajo[i].idNotebbok, descripcion, trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay trabajo en el sistema");
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
