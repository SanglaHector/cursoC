#include "validaciones.h"

int validarInt(int num,int min,int max){
    int retorno = -1;
    if ( num >= min && num <= max ){

        retorno = 1;
    }

    return retorno;
}
//**************************************************************************************************************


