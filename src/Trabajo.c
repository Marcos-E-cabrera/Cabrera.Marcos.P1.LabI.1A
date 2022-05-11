//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#include "Trabajo.h"
//
//int inicializarTrabajo(eTrabajo vec[], int tam)
//{
//    int todoOk = 0;
//    if(vec != NULL && tam > 0)
//    {
//        for(int i=0; i < tam; i++)
//        {
//            vec[i].isEmpty = 1;
//        }
//        todoOk = 1;
//    }
//    return todoOk;
//}
//
//int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
//{
//    int todoOk = 0;
//    if(vec != NULL && tam > 0 && pIndex != NULL)
//    {
//        *pIndex = -1;
//        for(int i=0; i < tam; i++)
//        {
//            if( vec[i].isEmpty )
//            {
//                *pIndex = i;
//                break;
//            }
//        }
//        todoOk = 1;
//    }
//    return todoOk;
//}
//
//int altaTrabajo(eTrabajo vec[], int tamT, eNotebook notebook[], int tamN, eServicio servicio[], int tamMerv, int* pIdTrabajo){
//    int todoOk = 0;
//    int indice;
//    eTrabajo newTrabajo;
//    eFecha fecha;
//
//    if(vec != NULL  && servicio != NULL && notebook != NULL && pIdTrabajo != NULL && tamT > 0 && tamN > 0)
//    {
//        system("cls");
//        printf("       *** Alta trabajo *** \n");
//        printf("-------------------------------------------\n\n");
//
//
//        if( buscarTrabajoLibre(vec, tamT, &indice) )
//        {
//            if(indice == - 1)
//            {
//                printf("No hay lugar en el sistema\n");
//            }
//            else
//            {
//                // aca caigo cuando haya lugar
//            	listarNotebook(vec, tamN, servicio);
//                printf("Ingrese id notebook\n");
//                scanf("%d", &newTrabajo.idNotebbok);
//                buscarNotebook(notebook, tamN, newTrabajo.idNotebbok, &indice);
//
//                while( indice == -1){
//                printf("notebook invalido. Ingrese id notebook\n");
//                scanf("%d", &newTrabajo.idNotebbok);
//                buscarNotebook(notebook, tamN, newTrabajo.idNotebbok, &indice);
//                }
//
//                listarServicio(servicio, tamMerv);
//                printf("Ingrese id servicio\n");
//                scanf("%d", &newTrabajo.idServicio);
//
//                while( !validarServicio(servicio, tamMerv, newTrabajo.idServicio )){
//                printf("servicio invalido. Ingrese id servicio\n");
//                scanf("%d", &newTrabajo.idServicio);
//                }
//
//                printf("Ingrese Fecha  dd/mm/aaaa: ");
//                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
//                newTrabajo.fecha = fecha;
//
//                newTrabajo.isEmpty = 0;
//                newTrabajo.id = *pIdTrabajo;
//                *pIdTrabajo = *pIdTrabajo + 1;
//                vec[indice] = newTrabajo;
//                todoOk = 1;
//            }
//        }
//        else
//        {
//            printf("Ocurrio un problema con los parametros\n");
//        }
//    }
//    return todoOk;
//}
//
////int listarTrabajo(eTrabajo vec[], int tamT, eNotebook notebook[], int tamN, eMarca marcas[], int tamM, eServicio servicio[], int tamMerv);
//
//int listarvec(eTrabajo vec[], int tamT, eNotebook notebook[], int tamN, eMarca marcas[], int tamM, eServicio servicio[], int tamMerv)
//{
//    int todoOk = 0;
//    int flag = 0;
//    char descripcion[20];
//
//     if(vec != NULL && marcas != NULL && servicio != NULL && notebook != NULL  && tamT > 0 && tamN > 0 && tamMerv > 0 && tamM > 0)
//    {
//        system("cls");
//        printf("          *** Listado de vec ***\n\n");
//        printf("  Id          IdNotebook        servicio    Fecha\n");
//        printf("--------------------------------------------------------------------------------\n");
//        for(int i=0; i < tamT; i++)
//        {
//            if( !vec[i].isEmpty )
//            {
//                cargarDescripcionServicio(servicio, tamMerv, vec[i].idServicio, descripcion);
//                printf("   %d     %d      %10s          %02d/%02d/%02d\n", vec[i].id, vec[i].idNotebbok, descripcion, vec[i].fecha.dia, vec[i].fecha.mes, vec[i].fecha.anio);
//                flag++;
//            }
//        }
//        if(flag == 0)
//        {
//            printf("       No hay vec en el sistema");
//        }
//        printf("\n\n");
//
//        todoOk = 1;
//    }
//    return todoOk;
//}
//
//
//
