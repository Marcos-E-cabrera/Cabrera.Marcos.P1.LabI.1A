#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int listarCliente(eCliente cliente[], int tamCliente)
{
int todoOk = 0;

    if(cliente != NULL && tamCliente > 0){
//    	system("cls");
    	printf("\n  ___________________________\n");
        printf(" |     LISTA DE CLIENTES     |\n");
        printf(" |---------------------------|\n");
        printf(" |  ID  |   SEXO    | NOMBRE |\n");
        printf(" |---------------------------|\n");
        for(int i=0; i < tamCliente; i++){
            printf(" | %-5d  %-12s|  %s    |\n", cliente[i].id, cliente[i].nombre, cliente[i].sexo);
        }
        printf(" |---------------------------|\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionCliente(eCliente cliente[], int tamCliente, int id, char descripcion[])
{
int todoOk = 0;
int indice;

    buscarCliente(cliente,tamCliente, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, cliente[indice].nombre);
       todoOk = 1;
    }
  return todoOk;
}

int buscarCliente(eCliente cliente[], int tamCliente, int id, int* pIndice){
    int todoOk = 0;
    if(cliente != NULL && tamCliente > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamCliente; i++){
                if(cliente[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarCliente(eCliente cliente[], int tamCliente, int id){
    int esValido = 0;
    int indice;

    buscarCliente(cliente, tamCliente, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


