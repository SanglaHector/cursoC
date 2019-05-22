#include "fecha.h"

int ordenPorFecha(eFecha fechaUno, eFecha fechaDos){//devuelvo 1 si la fecha 1 es menor, 2 si la fecha 2 es menor y 0 si son iguales
int retorno = 0;
    if(fechaUno.anio <= fechaDos.anio ){

        if (fechaUno.mes <= fechaDos.mes){
            if(fechaUno.dia < fechaDos.dia){
                retorno = 1;
            }else if ( fechaDos.dia == fechaUno.dia){
                retorno = 0;
            }else {
            retorno = 2;}
        }else{
        retorno = 2;}
    }else{
    retorno = 2;}
}
//********************************************
int validarFecha(int dia, int mes, int anio){

int validar = 0;
if( anio < 1900 && anio > 2020){
    switch(mes){
    case 1:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 2:
        if(dia > 0 && dia < 29){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 3:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 4:
        if(dia > 0 && dia < 31){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 5:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 6:
        if(dia > 0 && dia < 31){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 7:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 8:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 9:
        if(dia > 0 && dia < 31){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 10:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 11:
        if(dia > 0 && dia < 31){
            validar = 1;
        }else{ validar = -1;}
        break;
    case 12:
        if(dia > 0 && dia < 32){
            validar = 1;
        }else{ validar = -1;}
        break;

    default:
        validar = -1;
        break;
    }
}
return validar;
}
//***********************************
