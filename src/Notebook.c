#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Notebook.h"

int inicializarNotebook(eNotebook vec[], int tam){
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
                printf(" | * NO HAY LUGAR EN EL SISTEMA * |\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                printf(" |Ingrese el modelo de la Notebook : ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf(" |Modelo demasiado largo. Reingrese modelo: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(newNoterbook.modelo, auxCad);

				printf(" |Ingrese precio: ");
				fflush(stdin);
				scanf("%f", &newNoterbook.precio);

				while( newNoterbook.precio <= 1000 || newNoterbook.precio >= 90000)
				{
					printf(" |Precio invalido. Reingrese precio: ");
					fflush(stdin);
					scanf("%f", &newNoterbook.precio);
				}

                listarMarca(marcas, tamMarcas);

                printf(" |Ingrese ID MARCA: ");
                scanf("%d", &newNoterbook. idMarca);

                while( !validarMarca(marcas,tamMarcas, newNoterbook.idMarca))
                {
                    printf(" |MARCA Invalida. Ingrese ID MARCA: ");
                    scanf("%d", &newNoterbook.idMarca);
                }

                listarTipos(tipos, tamTipo);

                printf(" |Ingrese  ID TIPO: ");
                scanf("%d", &newNoterbook.idtipo);

                while( !validarTipo(tipos,tamTipo, newNoterbook.idtipo))
                {
                    printf(" |TIPO invalido. Ingrese ID TIPO: ");
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
            printf(" | * OCURRIO UN PROBLEMA CON LOS PARAMETROSO * |\n");
        }
    }
    return todoOk;
}

int bajaNotebook(eNotebook vec[], int tam, eTipo tipos[], eMarca marcas[])
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
    	listarNotebook(vec, tam, tipos, marcas);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf(" |No hay un empleado con id %d\n", id);
            }
            else
            {
            	mostrarNotebook(vec[indice], tipos, marcas, tam);
                printf("Confirma baja (s o n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf(" | * Baja cancelada por el usuario * |\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf(" | Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf(" | * Ocurrio un problema al buscar notebook * |\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarNotebook(eNotebook noterbook[], int tamNotebook, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarcas)
{
	int todoOk = 0;
	int indice;
	int id;
	char salir = 'n';

	if(noterbook != NULL && tamNotebook > 0)
	{
		listarNotebook(noterbook, tamNotebook, tipos, marcas);
		printf(" |Ingrese ID: ");
		scanf("%d", &id);
		printf("\n");

		if( buscarNotebook(noterbook, tamNotebook, id, &indice))
		{
			if(indice == -1)
			{
				printf(" |No hay un Notebook con ID %d\n", id);
			}
			else
			{
				mostrarNotebook(noterbook[indice], tipos, marcas, tamNotebook);
				do
				{
					system(" pause");
					switch(menuModificar()){
					case 1:
						printf(" |Ingrese precio: ");
						fflush(stdin);
						scanf("%f", &noterbook[indice].precio);
						printf("\n");

						while( noterbook[indice].precio <= 1000 || noterbook[indice].precio >= 90000)
						{
							printf(" |Precio invalido. Reingrese precio: ");
							fflush(stdin);
							scanf("%f", &noterbook[indice].precio);
							printf("\n");
						}

						printf(" | * SE HA MODIFICADO EL PRECIO * |\n");
						break;
					case 2:
						listarTipos(tipos, tamTipos);
		                printf(" |Ingrese ID TIPO: ");
		                scanf("%d", &noterbook[indice].idtipo);
		                printf("\n");

		                while( !validarTipo(tipos, tamNotebook, noterbook[indice].idtipo))
		                {
		                    printf(" |TIPO invalido. Ingrese ID TIPO: ");
		                    scanf("%d", &noterbook[indice].idtipo);
		                    printf("\n");
		                }
						printf("\n | * SE HA MODIFICADO EL TIPO DE NOTEBOOK * | \n");
						break;
					case 3:
						salir = 's';
						break;
					}

				}
				while(salir != 's');
			}
		}
		else
		{
			printf(" \n| * OCURRIO UN PROBLEMA AL BUSCAR NOTEBOOK * | \n");
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
    char letra;

    system("cls");
	printf("  ________________________\n");
	printf(" | * CAMPOS A MODIFICAR * |\n");
	printf(" |________________________|\n");
	printf(" | 1  |    PRECIO         |\n");
	printf(" | 2  |    TIPO           |\n");
	printf(" | 3  |    SALIR          |\n");
	printf(" |------------------------|\n");

	do{
		printf("  ___________________________________________");
		printf("\n | Por favor no ingrese letras, solo numeros |");
		printf("\n  __________________________");
		printf("\n | Introduzca una opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		scanf("%c", &letra);

	} while ((isalpha(letra))||(opcion < 1 || opcion > 3));
    return opcion;
}

int hardcodearNotebook(eNotebook vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eNotebook impostores[] =
    {
 //      id, modelo, idmarca, idtipo, precio, 0
        {0, "modelo1000xx1000zzy", 1000, 5003, 20000, 0},
        {0, "modelo1000xx1000zzy", 1001, 5002, 40000, 0},
        {0, "model1000xx1000zzy", 1002, 5001, 50000, 0},
        {0, "modelo0xx1000zzy", 1003, 5000, 60000, 0},
        {0, "modelo101000zzy", 1001, 5001, 70000, 0},
        {0, "m1000zzy", 1002, 5002, 30000, 0},
        {0, "modelo1000xx00zzy", 1003, 5003, 50000, 0},
        {0, "modelo1000xx10zzy", 1000, 5001, 80000, 0},
        {0, "modelo1000xx1000", 1001, 5002, 40000, 0},
        {0, "modelo1000xx1000zzy", 1002, 5002, 70000, 0}
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

int mostrarNotebook(eNotebook l, eTipo tipos[], eMarca marcas[], int tam)
{
    int todoOk = 0;
    char descTipo[20];
    char descMarca[20];

    if(tipos != NULL && tam > 0){
    	cargarDescripcionTipo( tipos, tam, l.idtipo, descTipo);
    	cargarDescripcionMarca( marcas, tam, l.idMarca, descMarca);
        printf(" | %-5d| %-20s| %-9.2f| %-10s| %-9s|\n",
        	l.id,
			l.modelo,
			l.precio,
			descTipo,
			descMarca
          );
    }
    return todoOk;
}

int listarNotebook(eNotebook list[], int tam, eTipo tipo[], eMarca marcas[])
{
    int todoOk = 0;
    int flag = 0;
    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("\n  ______________________________________________________________\n");
        printf(" |                     *** LISTA NOTEBOOK  ***                  |\n");
        printf(" |______________________________________________________________|\n");
        printf(" |  ID  |       MODELO        |  PRECIO  |    TIPO   |  MARCA   |\n");
        printf(" |--------------------------------------------------------------|\n");
        for(int i=0; i < tam; i++)
        {
            if( !list[i].isEmpty )
            {
            	mostrarNotebook(list[i], tipo, marcas, tam);
                flag++;
            }
        }
        printf(" |--------------------------------------------------------------|");

        if(flag == 0)
        {
            printf("       No hay Notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

// INFORME DE MARCAS

int menuMarca()
{
    int opcion;
    char letra;

    system("cls");
	printf("  ______________________________________________\n");
	printf(" |             * INFORME DE MARCA *             |\n");
	printf(" |______________________________________________|\n");
	printf(" | 1 | LISTAR MARCA                             |\n");
	printf(" | 2 | INFORMAR NOTEBOOKS DE UNA MARCA          |\n");
	printf(" | 3 | INFORMAR NOTEBOOKS POR MARCA             |\n");
	printf(" | 4 | INFORMAR CANTIDAD DE NOTEBOOKS POR MARCA |\n");
	printf(" | 5 | PROMEDIO DE PRECIOS DE UNA MARCA         |\n");
	printf(" | 6 | PROMEDIO DE PRECIOS POR MARCA            |\n");
	printf(" | 7 | MAYOR PRECIO DE UNA MARCA                |\n");
	printf(" | 8 | MARCA MAS CARA                           |\n");
	printf(" | 9 | SALIR                                    |\n");
	printf(" |----------------------------------------------|\n");

	do{
		printf("  ___________________________________________");
		printf("\n | Por favor no ingrese letras, solo numeros |");
		printf("\n  __________________________");
		printf("\n | Introduzca una opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		scanf("%c", &letra);

	} while ((isalpha(letra))||(opcion < 1 || opcion > 9));
    return opcion;
}

int informeMarca(eNotebook noterbook[], int tamNotebook, eMarca marcas[], int tamMarcas,eTipo tipos[])
{
	int todoOk = 0;
	char salir = 'n';

	if(marcas != NULL && noterbook != NULL && tamMarcas > 0 && tamNotebook > 0)
	{
		do
		{
			switch(menuMarca()){
			case 1:
				listarMarca(marcas, tamMarcas);
				system(" pause");
				break;
			case 2:
				informarNotebookMarca(noterbook, tamNotebook, marcas, tamMarcas, tipos);
				system(" pause");
				break;
			case 3:
				informarNotebookXMarca(noterbook, tamNotebook, marcas, tamMarcas, tipos);
				printf("\n\n");
				system(" pause");
				break;
			case 4:
				cantidadNotebookMarca(noterbook, tamNotebook, marcas, tamMarcas, tipos);
				printf("\n\n");
				system(" pause");
				break;
			case 5:
				promedioPrecioMarcaElegido(noterbook, tamNotebook, marcas, tamMarcas, tipos);
				printf("\n\n");
				system(" pause");
				break;
			case 6:
				promedioPrecioXMarca(noterbook, tamNotebook, marcas, tamMarcas, tipos);
				printf("\n\n");
				system(" pause");
				break;
			case 7:
				printf("\n\n");
				system(" pause");
				break;
			case 8:
				printf("\n\n");
				system(" pause");
				break;
			case 9:
				salir = 's';
				break;
			}
		}
		while(salir != 's');
	}
	else
	{
		printf(" \n| * OCURRIO UN PROBLEMA AL BUSCAR NOTEBOOK * | \n");
	}
	todoOk = 1;
	return todoOk;
}

int informarNotebookMarca(eNotebook noterbook[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[])
{
    int todoOk = 0;
    int idMarca;
    int flag = 1;
    char descripcion[20];

    if(noterbook != NULL && marcas != NULL && tamNotebook > 0 && tamMarcas > 0)
    {
        listarMarca(marcas, tamMarcas);

        printf(" |Ingrese Id Marca: ");
        scanf("%d", &idMarca);

        while( !validarMarca(marcas, tamMarcas, idMarca))
        {
            printf(" |Marca invalida. Ingrese Id Marca: ");
            scanf("%d", &idMarca);
        }

        for(int i=0; i < tamNotebook; i++)
        {
            if( !noterbook[i].isEmpty && noterbook[i].idMarca == idMarca)
            {
            	printf("  ______________________________________________________________\n");
                mostrarNotebook(noterbook[i], tipos, marcas, tamMarcas);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionMarca(marcas, tamMarcas, idMarca, descripcion);
            printf(" |No hay notebooks registradas en la marca %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int informarNotebookXMarca(eNotebook noterbook[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[])
{
	int todoOk = 0;
	int flag;

	if(marcas != NULL && noterbook != NULL && tamMarcas > 0 && tamNotebook > 0)
	{
		for(int s=0; s < tamMarcas; s++)
		{
			printf("\n  ______________________________________________________________\n");
			printf(" |                        %-6s                                |\n", marcas[s].descripcion);
			printf(" |______________________________________________________________|\n");
			printf(" |  ID  |       MODELO        |  PRECIO  |    TIPO   |  MARCA   |\n");
			printf(" |--------------------------------------------------------------|\n");

			flag = 1;
			for(int i=0; i < tamNotebook; i++)
			{
				if( !noterbook[i].isEmpty && noterbook[i].idMarca == marcas[s].id )
				{
					mostrarNotebook(noterbook[i], tipos, marcas, tamMarcas);
					flag = 0;
				}
			}

			if(flag)
			{
				printf("       No hay Notebooks en el sistema");
			}
			printf(" |--------------------------------------------------------------|");
		}
		todoOk = 1;
	}
	return todoOk;
}

int cantidadNotebookMarca(eNotebook noterbook[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[])
{
    int todoOk = 0;
    int cantidad;

    if(noterbook != NULL && marcas != NULL && tamNotebook > 0 && tamMarcas > 0)
    {
        for(int s=0; s < tamMarcas; s++)
        {
            cantidad = 0;
            printf("\n  ____________________\n");
            printf(" | MARCA | %-6s: ", marcas[s].descripcion);

            for(int e = 0; e < tamNotebook; e++)
            {
                if( !noterbook[e].isEmpty && noterbook[e].idMarca == marcas[s].id)
                {
                    cantidad++;
                }
            }
            printf("%d  |",cantidad);

        }
        todoOk = 1;
    }
    return todoOk;
}

int promedioPrecioMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, int idMarca, float* pPromedio)
{
    int todoOk = 0;
    float promedio = 0;
    float acumPrecio = 0;
    int contNotebook = 0;

    if(vec != NULL && marcas != NULL && pPromedio != NULL && tam > 0 && tamMarcas > 0 && validarMarca(marcas, tamMarcas, idMarca))
    {
        for(int i = 0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idMarca == idMarca)
            {
            	acumPrecio += vec[i].precio;
            	contNotebook++;
            }
        }
        if(contNotebook != 0)
        {
            promedio = acumPrecio/contNotebook;
        }

        *pPromedio = promedio;
        todoOk = 1;
    }
    return todoOk;
}

int promedioPrecioMarcaElegido(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, eTipo tipos[])
{
    int todoOk = 0;
    int idMarca;
    char descripcion[20];
    float promedio;

    if(vec != NULL && marcas != NULL && tam > 0 && tamMarcas > 0)
    {
    	listarMarca(marcas, tamMarcas);

    	printf(" |Ingrese Id Marca: ");
    	scanf("%d", &idMarca);

    	while( !validarMarca(marcas, tamMarcas, idMarca))
    	{
    		printf(" |Marca invalida. Ingrese Id Marca: ");
    		scanf("%d", &idMarca);
    	}

    	promedioPrecioMarca( vec, tam, marcas, tamMarcas, idMarca, &promedio);
        cargarDescripcionMarca(marcas, tamMarcas, idMarca, descripcion);

        printf(" |Promedio precio marca %s: $ %.2f", descripcion, promedio);
        todoOk = 1;
    }
    return todoOk;
}

int promedioPrecioXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMarcas, eTipo tipos[])
{
    int todoOk = 0;
    float promedio;

    if(vec != NULL && marcas != NULL && tam > 0 && tamMarcas > 0)
    {
    	for(int s=0; s < tamMarcas; s++)
        {
        	promedioPrecioMarca(vec, tam, marcas, tamMarcas, marcas[s].id, &promedio);
            printf("\n |Marca  %s: $ %.2f", marcas[s].descripcion, promedio);

        }
        todoOk = 1;
    }
    return todoOk;
}
