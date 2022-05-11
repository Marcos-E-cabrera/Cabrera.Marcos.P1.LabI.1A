#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int listarServicio(eServicio servicio[], int tam){
int todoOk = 0;

    if(servicio != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de servicio  ***\n");
        printf("  Id    Descripcion    Precio\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s  %5.2f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int buscarServicio(eServicio servicio[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(servicio != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(servicio[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarServicio(eServicio servicio[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarServicio(servicio, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int cargarDescripcionServicio(eServicio servicio[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarServicio(servicio,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, servicio[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


