#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int listarMarca(eMarca marca[], int tamMarcas)
{
int todoOk = 0;

    if(marca != NULL && tamMarcas > 0){
     // system("cls");
        printf("   *** Lista de marca  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamMarcas; i++){
            printf("   %4d    %10s\n", marca[i].id, marca[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionMarca(eMarca marca[], int tamMarcas, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarMarca(marca,tamMarcas, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, marca[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarMarca(eMarca marca[], int tamMarcas, int id, int* pIndice){
    int todoOk = 0;
    if(marca != NULL && tamMarcas > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamMarcas; i++){
                if(marca[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarMarca(eMarca marca[], int tamMarcas, int id){
    int esValido = 0;
    int indice;

    buscarMarca(marca, tamMarcas, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


