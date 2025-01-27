#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char str1[20],ch[20];
    int l,i,j,nb;
    printf("str 1 =");
    gets(str1);


    l=strlen(str1);

    i=0;
    j=0;
    nb=0;
    while(i<l){
        if ((str1[i]!='.')&& (str1[i]!=' ')){
            ch[j]=str1[i];
            j++;

        }
        else{
                ch[j]='\0';
                printf("%s-",ch);
                nb++;
                j=0;



        }
        i++;
    }
    printf("\n%d",nb);













    return 0;
}
