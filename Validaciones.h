#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//****************************************************
/**
*Retorna 1 si nombre es una cadena con caracteres alfabeticos
*Retorna -1 si nombre no es una cadena con caracteres alfabeticos
* \param   nombre[] char
* \return  int
**/
int validarNombre(char nombre[]);
//****************************************************
/**
**/
int isDigit(char numero[]);
//****************************************************
/**
**/
float charToFloat(char numero[]);
//****************************************************
/**
**/
int charToInt(char numero[]);
//**************************************************
/**
**/
int validarFloat(int min, int max, char num[]);
//**************************************************
/**
**/
int validarInt(int min, int max ,char num[]);
//****************************************************
/**
**/
void validarPatente(char patenteCar[],char patenteNum[], char patente[]);
//********************************
/**
**/
int isChar( char aux[]);
//********
/**
**/
void formatearNombre(char vec[]);
//********************************
/**
**/
int validarSexo(char sexo);
//*********************************
/**
**/
int compararPatentes(char patenteUsuario[6],char patenteDato[6]);
//**********************************
/**
**/
int compararFechas(int diaDato, int mesDato, int anioDato, int diaIngresado, int mesIngresado, int anioIngresado);
//*********************************
/**
**/
int validarIntdesdeInt(int numero);
