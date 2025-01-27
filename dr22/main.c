#include <stdio.h>
#include <stdlib.h>

int main()
{

    char ch[20],ch2[20];
    int l,le,i,j,b;

    printf("ch=\n");
    gets(ch);
    printf("ch 2 =\n");
    gets(ch2);
    l=strlen(ch);
    le=strlen(ch2);

    i=0;
    j=0;
    b=1;

    while ((j<l)&& (i<le)&& (b==1)) {
            if (ch2[i]==ch[j]){
                    i++;



            }
            else {
                j++;
                if (j==(l)){
                    b=0;
                }
            }

    }

    if (b==0){
        printf("non \n");
    }
    else {
        printf("oui");
    }
    return 0;
}
