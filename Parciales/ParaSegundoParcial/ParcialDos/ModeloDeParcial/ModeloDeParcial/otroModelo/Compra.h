#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "LinkedList.h"

struct S_Compra
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
};
typedef struct S_Compra Compra;

void com_calcularMonto(void* p);
Compra* compra_new();
Compra* compra_newParametros(char* nombreStr,char* idStr,char* precioStr, char* unidadesStr,char* ivaStr);
int compra_setNombre(Compra* this,char nombre[128]);
int compra_setId(Compra* this,int idProducto);
int compra_setPrecio(Compra* this, float precio);
int compra_setUnidades(Compra* this, int unidades);
int compra_setIva(Compra* this, float iva);
//int compra_setMontonTotal(Compra* this, float monto);

int compra_getIva(Compra* this,float* iva);
int compra_getUnidades(Compra* this,int* unidades);
int compra_getPrecio(Compra* this,float* precio);
int compra_getNombre(Compra* this,char* nombre);
int compra_getId(Compra* this,int* id);

int compras_mostrar(LinkedList* this);
void mostrarCompra(LinkedList* lista);

#endif // COMPRA_H_INCLUDED
