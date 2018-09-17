#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector [20] = {5,9,65,18,56,87,46,32,0,36,56,84,55,23,1,59,9,7,100,56};
    int i;
    int j;
    int auxiliar;
    for( i =  0; i < 20 ; i++)
    {
        for ( j = i+1 ; j <= 20 ; j++)
        {

            if ( vector [i] > vector[j])
            {
               auxiliar = vector[i];
               vector[i]=vector[j];
               vector[j]=auxiliar;
            }
        }
    }
    for ( i = 0 ; i < 20 ;  i++)
    {
        printf("%d \n",  vector[i]);
    }

    return 0;
}
