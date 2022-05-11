/*
 ============================================================================
 Name        : 1A.c
 Author      : marcos cabrera
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "Trabajo.h"

#define TAM 10
#define TAM_MARCA 4
#define TAM_TIPO 4
#define TAM_SERV 4
#define TAM_TRA 10

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	char letra;

	int proximoId = 100;
    //int proximoIdTrabajo = 300;
	eNotebook lista[TAM];

//	eTrabajo trabajo[TAM_TRA];

	eMarca marcas[TAM_MARCA] ={
		{1000, "Compaq"},
		{1001, "Asus"},
		{1002, "Acer"},
		{1002, "HP"}
	};

	eTipo tipo[TAM_TIPO] ={
		{5000, " Gamer"},
		{5001, "Disenio"},
		{5002, "Ultrabook"},
		{5003, "Normalita"}
	};

	eServicio servicio[TAM_SERV] ={
		{20000, " Bateria", 2250},
		{20001, "Display", 10300},
		{20002, "Mantenimiento", 4400},
		{20003, "Fuente", 5600}
	};

	inicializarNotebook(lista, TAM);

//	hardcodearPasajeros(lista, ELEMENTS, 5, &proximoId);

	do{
		system("cls");
		printf("\n       | * MENU DE ANSI *   |\n");
		printf(" |  1) ALTA NOTEBOOK \n");
		printf(" |  2) MODIFICAR NOTEBOOK\n");
		printf(" |  3) BAJA NOTEBOOK\n");
		printf(" |  4) LISTAR NOTEBOOKS\n");
		printf(" |  5) LISTAR MARCAS\n");
		printf(" |  6) LISTAR TIPOS\n");
		printf(" |  7) LISTAR SERVICIOS\n");
		printf(" |  8) ALTA TRABAJO\n");
		printf(" |  9) LISTAR TRABAJOS\n");
		printf(" |  10) Salir\n");

		do{ /* Filtro de la opción elegida por el usuario */
			printf("\n | Por favor no ingrese letras, solo numeros");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
			scanf("%c", &letra);
		} while ((isalpha(letra))||(opcion < 1 || opcion >10));

		system("cls");

		switch ( opcion ){
		case 1:
            if( altaNotebook(lista, TAM, marcas , TAM_MARCA , tipo, TAM_TIPO, &proximoId))
            {
                printf("Noterbook agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de Noterbook\n");
            }
			break;
		case 2:
            if( modificarNotebook(lista, tipo, TAM_TIPO) == 0)
            {
                printf("Problema al hacer la modificacion de Notebook\n");
            }
			break;
		case 3:
            if( bajaNotebook(lista, TAM, tipo) == 0)
            {
                printf("Problema al hacer la baja de empleado\n");
            }
			break;
		case 4:
			listarNotebook(lista, TAM, tipo);
			break;
		case 5:
			listarMarca(marcas, TAM_MARCA);
			break;
		case 6:
			listarTipos(tipo, TAM_TIPO);
			break;
		case 7:
			listarServicio(servicio, TAM_SERV);
			break;
		case 8:
//            if(altaTrabajo(trabajo, TAM_TRA, lista, TAM, marcas, TAM_MARCA, servicio, TAM_SERV, &proximoIdTrabajo))
//            {
//                printf("trabajo agregado con exito!!!\n");
//            }
//            else
//            {
//                printf("Problema al hacer el alta de trabajo\n");
//            }
			break;
		case 9:
//
			break;
		}
		system("pause");
	}while((isalpha(letra)) || (opcion !=10) );
	return EXIT_SUCCESS;
}
