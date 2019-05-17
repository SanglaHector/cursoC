#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"


int informes_ordenar_pantalla_Nombre_Precio(Pantalla* array, int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {

                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && ordenNombre) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !ordenNombre)) //******
                    {

                        if((array[i].precio > array[i+1].precio) > 0 && ordenPrecio){


                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;

                            auxiliarPrecio = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarPrecio;
                            flagSwap = 1;

                        }

                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;


}


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}
