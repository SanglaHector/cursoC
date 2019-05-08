#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
/**
\brief
 *Retorna 1 si num esta entre min y max.
 *Retorna -1 si num no esta entre min y max
 * \param  num int
 * \param  min int
 * \param  max int
 * \return int
**/
int validarInt(int num,int min,int max);
//*****************************************************
/**
*Retorna 1 si num esta entre min y max
*Retorna -1 si num no esta entre min y max
* \param   num  float
* \param   min  float
* \param   max  float
* \return  int
**/
int validarFloat(float num, float min, float max);
//****************************************************
/**
*Retorna 1 si nombre es una cadena con caracteres alfabeticos
*Retorna -1 si nombre no es una cadena con caracteres alfabeticos
* \param   nombre[] char
* \return  int
**/
int validarNombre(char nombre[]);
//****************************************************
