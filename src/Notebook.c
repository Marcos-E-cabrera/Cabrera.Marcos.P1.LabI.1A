#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebook.h"


int inicializarNotebook(eNotebook vec[], int tam)
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

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
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

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas,  eTipo tipos[], int tamTipo, int* pId)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eNotebook newNoterbook;

    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( buscarNotebookLibre(vec, tam, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                printf("Ingrese el modelo de la Notebook : ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("modelo demasiado largo. Reingrese modelo: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(newNoterbook.modelo, auxCad);

				printf("|Ingrese precio: ");
				fflush(stdin);
				scanf("%f", &newNoterbook.precio);

				while( newNoterbook.precio <= 1000 || newNoterbook.precio >= 90000)
				{
					printf("|Precio invalido. Reingrese precio: ");
					fflush(stdin);
					scanf("%f", &newNoterbook.precio);
				}

                listarMarca(marcas, tamMarcas);

                printf("Ingrese Id marca: ");
                scanf("%d", &newNoterbook. idMarca);

                while( !validarMarca(marcas,tamMarcas, newNoterbook.idMarca))
                {
                    printf("Sector invalido.Ingrese Id sector: ");
                    scanf("%d", &newNoterbook.idMarca);
                }

                listarTipos(tipos, tamTipo);

                printf("Ingrese Id tipo: ");
                scanf("%d", &newNoterbook.idtipo);

                while( !validarTipo(tipos,tamTipo, newNoterbook.idtipo))
                {
                    printf("Sector invalido. Ingrese Id tipo: ");
                    scanf("%d", &newNoterbook.idtipo);
                }

                newNoterbook.isEmpty = 0;
                newNoterbook.id = *pId;
                *pId = *pId + 1;
                vec[indice] = newNoterbook;
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

int mostrarNotebook(eNotebook l, eTipo tipos[], int tam)
{
    int todoOk = 0;
    char descTipo[20];

    if(tipos != NULL && tam > 0){
    	cargarDescripcionTipo( tipos, tam, l.idtipo, descTipo);
        printf("   %4d    %20s      %9.2f    %20s\n",
        	l.id,
			l.modelo,
			l.precio,
			descTipo
          );
        todoOk = 1;
    }
    return todoOk;
}

int listarNotebook(eNotebook list[], int tam, eTipo tipo[])
{
    int todoOk = 0;
    int flag = 0;
    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("                        *** LISTA NOTEBOOK ***\n\n");
        printf("    ID     |         MODELO         |     PRECIO     |     TIPO     |\n");
        printf("-------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !list[i].isEmpty )
            {
            	mostrarNotebook(list[i], tipo, tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay Notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int modificarNotebook(eNotebook noterbook[], eTipo tipos[], int tam)
{
	int todoOk = 0;
	int indice;
	int id;
	char salir = 'n';

	if(noterbook != NULL && tam > 0)
	{
		listarNotebook(noterbook, tam, tipos);
		printf("Ingrese id: ");
		scanf("%d", &id);
		if( buscarNotebook(noterbook, tam, id, &indice))
		{
			if(indice == -1)
			{
				printf("No hay un Notebook con id %d\n", id);
			}
			else
			{
				mostrarNotebook(noterbook[indice], tipos, tam);
				do
				{
					switch(menuModificar()){
					case 1:
						printf("|Ingrese precio: ");
						fflush(stdin);
						scanf("%f", &noterbook[indice].precio);

						while( noterbook[indice].precio <= 1000 || noterbook[indice].precio >= 90000)
						{
							printf("|Precio invalido. Reingrese precio: ");
							fflush(stdin);
							scanf("%f", &noterbook[indice].precio);
						}

						printf("Se ha modificado el precio\n");
						break;
					case 2:

		                listarTipos(tipos, tam);

		                printf("Ingrese Id tipo: ");
		                scanf("%d", &noterbook[indice].idtipo);

		                while( !validarTipo(tipos, tam, noterbook[indice].idtipo))
		                {
		                    printf("Sector invalido. Ingrese Id tipo: ");
		                    scanf("%d", &noterbook[indice].idtipo);
		                }
						printf("Se ha modificado el tipo de Notebook\n");
						break;
					case 3:
						salir = 's';
						break;
					}
					system("pause");
				}
				while(salir != 's');
			}
		}
		else
		{
			printf("Ocurrio un problema al buscar empleado\n");
		}
		todoOk = 1;
	    }
	return todoOk;
}

int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificar()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- precio\n");
    printf("2- tipo\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int bajaNotebook(eNotebook vec[], int tam, eTipo tipos[])
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
    	listarNotebook(vec, tam, tipos);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con id %d\n", id);
            }
            else
            {
            	mostrarNotebook(vec[indice], tipos, tam);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar notebook\n");
        }
        todoOk = 1;
    }
    return todoOk;
}





















