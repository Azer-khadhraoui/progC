#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char v[20],ch[20];
    int i,lem,x,len;




            printf("donner la chaine \n");
            fflush(stdin);
            scanf("%s",v);
               printf("donner la chaine 2 \n");
            fflush(stdin);
            scanf("%s",ch);




    printf("x=");
    scanf("%d",&x);
len=strlen(ch);
lem=strlen(v);
    for (i=x;i<len;i++){
            v[lem+i-x]=ch[i];

    }v[lem+i-x]='\0';

    puts(v);






    return 0;
}
