#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[20] = {2,36,56,54,85,98,78,41,22,0,36,5,9,8,7,55,78,81,56,92};
    int i;
    int j;
    int auxiliar;

    for(i = 0 ; i < 20 ; i++)
    {
        printf("%d\n" ,  vector[i]);
    }

    for( i = 0 ; i < 20 ; i++)
    {
        for ( j = i+1 ; j < 20 ; j++)
        {
            if( vector[i] > vector [j])
            {
                auxiliar = vector[j];
                vector[j] = vector [i];
                vector  [i] = auxiliar;
            }
        }
    }
    for( i = 0 ; i < 20 ; i++)
    {
        printf("%d\n " ,vector[i] );
    }

    return 0;
}
