#include <stdio.h>
#include <stdlib.h>
#define A 3
/* Arrancamos con estructuras. CLASE, simular a un concepto de "clase", cosa que vamos a aplicar y terminar de formar el cuatri que viene
Estructura != clase.
LAs estructuras tiene porpiedades.

Se declaran por afuera del main
¡ como se define?
typedef = definimos un nuevo tipo de dato
typedef struct   hablamos de atributos como sinonimos de campos // Le tenemos que poner nombre
{

}nombre s De struct o e de estructura. eAlumno.
*/

typedef struct
{
    int legajo;
    char nombre[50]; // No necesito la matriz ya que me la da la estructura.LA estructura no guarda datos, estoy definiendo un nuevo tipo de dato
    //Lo que estoy haceidno es crear una variable, reservo memoria para guardar los datos.
    float altura;
    int nota;
}eAlumno;

//las funciones se desclaran por debajo de las estructuras.
void mostrarUnAlumno(eAlumno);
// tenemos que crear espacio para guardar esas variables

eAlumno cargarUnAlumno();

void cargarListadoDeAlumno(eAlumno[], int);
void mostrarListadoDeAlumno(eAlumno[], int);
int main()
{
    eAlumno miAlumno;/*= {132,"Juan",1.84,7};;*/ // miAlumno es el nombre de mi variable.
     //En el mismo orden en que fueron obtenidos los campos.
    //Muestro los datos: Descompongo la
    /*eAlumno otroAlumno;
*/    eAlumno miAlumnoMain;

    eAlumno listadoMain  [A];

    cargarListadoDeAlumno(listadoMain , A);
    mostrarListadoDeAlumno(listadoMain, A );
    /*miAlumnoMain = cargarUnAlumno();
    mostrarUnAlumno(miAlumnoMain);*/

   /* otroAlumno = miAlumno;// si muestro OtroAlumno , lo muestra igual*/

   // mostrarUnAlumno(miAlumno);
    return 0;
}
//Como funcion? Cada vez que declara un aliumno recerva un espacio COMO MINIMO la sumatoria de todos los tipos de datos que defini en el struct.
//legajo = 4 , nombre = 50 etc, me reserva la cantidad de bites de la suma de todas esas variables.
//Que hace el sistema opertaivo con esto?
void mostrarUnAlumno(eAlumno unAlumno)
{
    printf("%d --%s--%f--%d\n", unAlumno.legajo,unAlumno.nombre,unAlumno.altura,unAlumno.nota);
}
eAlumno cargarUnAlumno()
{
    eAlumno miAlumno;
     printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s",miAlumno.nombre);
    //gets (miAlumno.nombre);

    printf("Ingrese altura: ");
    scanf("%f",&miAlumno.altura);

    printf("Ingrese nota: ");
    scanf("%d",&miAlumno.nota);
    //Los porcentuales tienen que ir en orden
    //y miAlumno.
    return miAlumno;
}

void cargarListadoDeAlumno(eAlumno listado[], int tam)
{
    int i;
    for( i = 0 ; i < tam ; i++)
    {
        listado[i] = cargarUnAlumno();
    }

}
void mostrarListadoDeAlumno(eAlumno listado[], int tam)
{
    int i;
    for ( i = 0 ; i < tam ; i++ )
    {
        mostrarUnAlumno(listado[i]);
    }
}
