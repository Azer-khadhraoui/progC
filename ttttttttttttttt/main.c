#include <stdio.h>
#include <stdlib.h>

int main()
{

    int value;
    int absoluteValue;

    printf( "Veuillez saisir un entier : " );
    scanf( "%d", &value );

    absoluteValue = abs( value );

    printf( "La valeur absolue de %d vaut %d.\n", value, absoluteValue );
    return 0;
}
