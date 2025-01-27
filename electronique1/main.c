#include <stdio.h>

unsigned char u_var = 0;
char s_var = 0;

int main() {

    printf("Variable sizes (in bytes):\n");

    u_var = sizeof(char);
    printf("Char variable: %d\n", u_var);

    u_var = sizeof(short);
    printf("Short variable: %d\n", u_var);

    u_var = sizeof(int);
    printf("Int variable: %d\n", u_var);

    /********************************************************************/


    printf("\nOperation results:\n");

    u_var = 27;
    printf("a. u_var = %d\n", u_var);

    u_var = 283;
    printf("b. u_var = %d\n", u_var);

    u_var = 511;
    printf("c. u_var = %d\n", u_var);

    s_var = 511;
    printf("d. s_var = %d\n", s_var);

    s_var = 131;
    printf("e. s_var = %d\n", s_var);

    s_var = -132 - 64;
    printf("f. s_var = %d\n", s_var);

    s_var = 95 + 50;
    printf("g. s_var = %d\n", s_var);

    return 0;
}
