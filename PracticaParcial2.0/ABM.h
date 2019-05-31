#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Colores.h"
#include "Servicios.h"
#include "validaciones.h"
#include "Marca.h"
#include "auto.h"
#include "Trabajo.h"
#include "Clientes.h"
#define OCUPADO 1
#define VACIO 0
//*****************************
/**
**/
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec[],int tamCol,eCliente vecCli[], int tamCli);
//*******************************
/**
**/
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol,eCliente vecCli[], int tamCli);
//************************************
/**
**/
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,eCliente vecCli[], int tamCli);
//********************************
/**
**/
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol,eCliente vecCli[], int tamCli);
//********************************
/**
**/
void mostrarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,eCliente vecCli[], int tamCli);
//********************************
/**
**/
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,eCliente vecCli[], int tamCli);
//*****************************
/**
**/
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice,eCliente vecCli[], int tamCli);
//*******************************
/**
**/
int buscarLleno(eAuto vec[],  int tam);
//********************************
//********************************************************************************************************
//********************************LISTADOS****************************************************************
//********************************************************************************************************
/**
**/
void listarMarcas(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
/**
**/
void listarColores(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
/**
**/
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,eCliente vecCli[], int tamCli);
//********************************
//******************************************************************************************************
//********************************TRABAJO***************************************************************
//******************************************************************************************************
/**
**/
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer);
//********************************
/**
**/
void mostrarTrabajo(eTrabajo vecTra, eServicio vecSer[], int tamSer);
//*********************************
/**
**/
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra);
//*********************************
/**
**/
void pedirDatosTra(eTrabajo vecTra[], int tamTra, eAuto vecAuto[], int tamAuto, eServicio vecSer[], int tamSer,int indice);
//***********************************
/**
**/
void programaTrabajos(eTrabajo vecTra[], int tamTra, eAuto vecAuto[], int tamAuto, eServicio vecSer[], int tamSer);
//***********************************
/**
**/
void modificarTrabajo(eTrabajo vec[],  int tam, eServicio vecSer[], int tamSer, eAuto vecAuto[], int tamAuto);
//************************************************
/**
**/
void bajaTrabajo(eTrabajo vec[], int tam, eServicio vecSer[], int tamSer);
//************************************************
/**
**/
void listados(eAuto autos[],int tamAuto,eColor colores[] ,int tamCol,eMarca marcas[],int tamMar,eServicio servicios[] ,int tamSer,eTrabajo trabajos[],int tamTra,eCliente clientes[],int tamCli);
//*************************************************
/**
**/
void mostrarAutosDeUnColorDeterminado(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eCliente clientes[], int tamCli,eMarca marcas[], int tamMar);
//***********************************************
/**
**/
void mostrarAutosDeUnaMarcaDeterminado(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eCliente clientes[], int tamCli,eMarca marcas[], int tamMar);
//*************************************************
/**
**/
void mostrarTrabajosDeAuto(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//***********************************************
/**
**/
void mostrarAutosSinTrabajo(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//************************************************
/**
**/
void importeTotalDeTrabajosPorAuto(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//************************************************
/**
**/
void mostrarServicioMasPedido(eTrabajo trabajos[], int tamTra,eServicio servicios[], int tamSer);
//************************************************
/**
**/
//**********************************
/**
**/
void mostrarServicioMasPedido(eTrabajo trabajos[], int tamTra,eServicio servicios[], int tamSer);
//************************************************
/**
**/
void recaudacionPorFecha(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//************************************************
/**
**/
void mostrarAutosQueRealizaronUnServicioSeleccionado(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//************************************************
/**
**/
void trabajosRealizadosEnAutosDeColor(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//***********************************************
/**
**/
void facturacionTotalPorServicio(eServicio servicios[], int tamSer, eTrabajo trabajos[], int tamTra);
//***********************************************
/**
**/
void masCantidadDeUnServicioPorMarca(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//*************************************************
/**
**/
void mostrarAutosQueTuvieronTrabajoEnDeterminadaFecha(eAuto autos[], int tamAuto, eColor colores[], int tamCol, eMarca marcas[],int tamMar,eCliente clientes[], int tamCli,eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
//*************************************************
