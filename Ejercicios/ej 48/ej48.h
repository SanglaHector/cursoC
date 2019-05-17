#ifndef EJ48_H_INCLUDED
#define EJ48_H_INCLUDED
typedef struct eEmpleados {
char nombre[30];
char apellido[30];
int salario;
int horas;
int legajo;
}eEmpleados;
int menu ();
void ingresarEmpleado(char nombre[30],  char apellido[30], int salario);
void imprimirDatosIngresados(char nombre[30], char apellido[30], int salario,  int legajo);
void modificarDatos(int legajo , char nombre[20],  char apellido[20], int salario, int legajoInterno);
void eliminarEmpleado();

#endif // EJ48_H_INCLUDED
