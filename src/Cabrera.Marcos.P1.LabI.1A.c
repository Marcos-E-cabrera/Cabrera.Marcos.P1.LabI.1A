/*
 ============================================================================
 Name        : 1A.c
 Author      : marcos cabrera
 Version     : 1.1
 Copyright   : Your copyright notice
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// LIBRERIAS
#include "cliente.h"
#include "Notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "Trabajo.h"

/// TAMANIO ARRAY
#define TAM 10
#define TAM_CLIENTE 10
#define TAM_MARCA 4
#define TAM_TIPO 4
#define TAM_SERV 4
#define TAM_TRA 10

int main(void){
	setbuf(stdout, NULL);
	int opcion;
	char letra;
	int flag = 0;

	/// --------------- ID
	int proximoId = 100;
    int proximoIdTrabajo = 300;

    /// ------ LISTADO NOTEBOOK
    eNotebook lista[TAM];

    /// ------ LISTADO TRABAJO
	eTrabajo trabajo[TAM_TRA];

	/// ------ CLIENTE
	eCliente cliente[TAM_CLIENTE] ={
		{7000,"Juan",     "m"},
		{7001,"Valentina","f"},
		{7002,"Marcos",   "m"},
		{7003,"Mauro",    "m"},
		{7004,"Roser",    "m"},
		{7005,"Matilde",  "f"},
		{7006,"Maria",    "f"},
		{7007,"Juan",     "m"},
		{7008,"Marta",    "f"},
		{7009,"Mike",     "m"}
	};
	/// ------ LISTADO MARCAS
	eMarca marcas[TAM_MARCA] ={
		{1000, "Compaq"},
		{1001, "Asus"},
		{1002, "Acer"},
		{1003, "HP"}
	};

	/// ------ LISTADO TIPOS
	eTipo tipo[TAM_TIPO] ={
		{5000, "Gamer"},
		{5001, "Disenio"},
		{5002, "Ultrabook"},
		{5003, "Normalita"}
	};

	/// ------ LISTADO SERVICIOS
	eServicio servicio[TAM_SERV] ={
		{20000, "Bateria", 2250},
		{20001, "Display", 10300},
		{20002, "Mantenimiento", 4400},
		{20003, "Fuente", 5600}
	};

	/// --------------- INICIALIZACIONES
	inicializarNotebook(lista, TAM);
	inicializarTrabajos(trabajo, TAM_TRA);
	hardcodearNotebook(lista, TAM, 9, &proximoId);
	hardcodearTrabajo(trabajo, TAM, 9, &proximoIdTrabajo);

	/// --------------- MENU VALIDADO
	do{
		system("cls");
		printf("\n  __________________________________________________\n");
		printf(" |                   * MENU DE ANSI *               |\n");
		printf(" |__________________________________________________|\n");
		printf(" | 1  | ALTA NOTEBOOK                               |\n");
		printf(" | 2  | MODIFICAR NOTEBOOK                          |\n");
		printf(" | 3  | BAJA NOTEBOOK                               |\n");
		printf(" | 4  | LISTAR NOTEBOOKS                            |\n");
		printf(" | 5  | LISTAR MARCAS                               |\n");
		printf(" | 6  | LISTAR TIPOS                                |\n");
		printf(" | 7  | LISTAR SERVICIOS                            |\n");
		printf(" | 8  | ALTA TRABAJO                                |\n");
		printf(" | 9  | LISTAR TRABAJOS                             |\n");
		printf(" | 10 | LISTAR IMFORMES                             |\n");
		printf(" | 11 | Salir                                       |\n");
		printf(" |--------------------------------------------------|\n");

		do{
			printf("  ___________________________________________");
			printf("\n | Por favor no ingrese letras, solo numeros |");
			printf("\n  __________________________");
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
            	flag = 1;
                printf(" |Noterbook agregado con exito!!!\n");
            }
            else
            {
                printf(" | * Problema al hacer el alta de Noterbook * |\n");
            }
			break;
		case 2:
			if (flag == 1 || proximoId > 100 )
			{
				if( modificarNotebook(lista, TAM, tipo, TAM_TIPO, marcas, TAM_MARCA, cliente, TAM_CLIENTE) == 0)
				{
					printf(" | * Problema al hacer la modificacion de Notebook * |\n");
				}
			}
			break;
		case 3:
			if (flag == 1 || proximoId > 100)
			{

				if( bajaNotebook(lista, TAM, tipo, marcas, cliente) == 0)
				{
					printf(" | * Problema al hacer la baja de Notebook * |\n");
				}

			}
			break;
		case 4:
			listarNotebook(lista, TAM, tipo, marcas, cliente);
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
            if(altaTrabajo(trabajo, TAM_TRA, lista, TAM, marcas, TAM_MARCA, tipo, TAM_TIPO,servicio, TAM_SERV, cliente, TAM_CLIENTE, &proximoIdTrabajo))
            {
                printf(" |Trabajo agregado con exito!!!\n");
            }
            else
            {
                printf(" | * Problema al hacer el alta de trabajo * |\n");
            }
			break;
		case 9:
			listarTrabajo(trabajo, lista , servicio, TAM_TRA);
			break;
		case 10:
			informes(lista, TAM, marcas, TAM_MARCA, tipo,TAM_TIPO, cliente);
			break;
		}
		system("pause");
	}while((isalpha(letra)) || (opcion !=11) );
	return EXIT_SUCCESS;
}
