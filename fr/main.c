#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch[20];
    int i,nb,l;

    printf("ch=\n");
    scanf("%s",ch);
    l=strlen(ch);
    nb=0;
    for (i=0;i<l;i++){
        if ((ch[i]=='A') || (ch[i]=='a')){
                nb++;

        }
    }


    printf ("%d\n",nb);

        for (i=0;i<l;i++){
        if ((ch[i]=='A') || (ch[i]=='a')){
                ch[i]='@';

        }
    }
    printf("%s",ch);






    return 0;
}
