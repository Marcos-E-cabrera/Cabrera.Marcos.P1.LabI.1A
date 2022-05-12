#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

int validarfecha(eFecha *fecha);

//printf("Ingrese Fecha dd/mm/aaaa: ");
//scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
//
//validar = validarfecha(&fecha);
//{
//	printf("error fecha %d/%d/%d",fecha.dia,fecha.mes,fecha.anio);//TOMAMOS TRES VARIABLES JUNTAS
//	printf("Reingrese Fecha dd/mm/aaaa: ");
//	scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
//	validar =validarfecha(&fecha);
//}
//nuevoTrabajo.fecha = fecha;
