#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int listarTipos(eTipo tipos[], int tamTipos)
{
int todoOk = 0;

    if(tipos != NULL && tamTipos > 0){
     // system("cls");
        printf("   *** Lista de tipos  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamTipos; i++){
            printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tamTipos, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarTipo(tipos,tamTipos, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, tipos[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarTipo(eTipo tipos[], int tamTipos, int id, int* pIndice){
    int todoOk = 0;
    if(tipos != NULL && tamTipos > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamTipos; i++){
                if(tipos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo tipos[], int tamTipos, int id){
    int esValido = 0;
    int indice;

    buscarTipo(tipos, tamTipos, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


