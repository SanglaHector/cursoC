#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parcer.h"
#include "Dominio.h"

int evaluarTipo(eDominio* elemento,int tipo);
int main()
{

    LinkedList* lista;
    lista = ll_newLinkedList();

    FILE* f;
    FILE* pf;
    eDominio* pElemento;
    char path[100];
    int tipo;

      int opcion = 0;
    do{
        printf("\n1.Cargar Datos");
        printf("\n2.Mostrar con descripcion");
        printf("\n3.Generar archivo de llamadas");
        printf("\n4.Salir");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:

                printf("\nIngrese el nombre del archivo que quiera cargar.");
                scanf("%s", path);
                if((f = fopen(path,"r")) != NULL)
                {
                    if(parser_FromText(f,lista) != 0)
                    {
                        printf("\nLectura correcta!! \n");
                        d_list(lista);

                    }else
                    {
                        printf("\nError en parceo");
                    }
                }else
                {
                    printf("\nError al abrir al archivo");
                }
                break;
            case 2:
                if(ll_len(lista) > 0)
                {

                    d_listConDescripcion(lista);
                }
                break;
            case 3:
                if(ll_len(lista) > 0)
                {
                    LinkedList* nuevaLista = ll_newLinkedList();
                    pf = fopen("NuevoArchivo.csv","w");

                    printf("\nIngrese un numero del 1 al 5.");
                    scanf("%d",&tipo);
                    if(tipo > 0 && tipo < 6)
                    {
                        nuevaLista = ll_filterPAraDominio(lista,evaluarTipo,tipo);

                         if(nuevaLista != NULL)
                        {
                            fprintf(pf,"%s,%s,%s,%s,%s\n","Id_Llamada","Fecha","Numero_cliente","ID_problema","Solucionado");

                            for(int i = 0; i < ll_len(nuevaLista); i++)
                            {
                                pElemento = (eDominio*)ll_get(nuevaLista, i);
                                fprintf(pf,"%d,%s,%d,%d,%s\n",pElemento->id,pElemento->fecha,pElemento->numeroCliente,pElemento->idProblema,pElemento->problemaSolucionado);
                            }
                            fclose(pf);
                        }

                    }else
                    {
                        printf("\nIngrese un tipo correcto");
                    }

                }

                break;
        }
    }while(opcion != 4);
}
int evaluarTipo(eDominio* elemento,int tipo)
{
    int retorno = 0;
    if( elemento != NULL )
    {
        if(elemento->idProblema == tipo)
        {
            retorno = 1;
        }
    }

    return retorno;
}
