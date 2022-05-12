#include "Fecha.h"

int validarfecha(eFecha *fecha)
{
	int fechaValida = 0;

	if (fecha->anio >= 1970 && fecha->anio <= 2022 ){
		if( fecha->mes >= 1 && fecha->mes <= 12 ){
			switch( fecha->mes ){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if( fecha->dia >= 1 && fecha->dia <= 31 ){
					fechaValida = 1;
				}
				break;
			case 4: case 6: case 9: case 11:
				if( fecha->dia >= 1 && fecha->dia <= 30 ){
					fechaValida = 1;
				}
				break;
			case 2:
				if( ((fecha->anio%4 == 0)   &&   (fecha->anio%100 != 0))   ||   (fecha->anio%400 == 0) ){
					if( fecha->dia >= 1 && fecha->dia <= 29 ){
						fechaValida = 1;
					}
				}
				else{
					if(fecha->dia >= 1 && fecha->dia <= 28 ){
						fechaValida = 1;
					}
				}
				break;
			}
		}
	}
	return fechaValida;
}
