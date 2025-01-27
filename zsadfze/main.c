#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char ch[20],sch[20],so[40];
    int l,l1,i,j,k,nb;
    printf("ch=\n");
    fflush(stdin);
    gets(ch);
    printf("sch=\n");
    fflush(stdin);
    gets(sch);

     l=strlen(ch);
     l1=strlen(sch);

    i=0;
    k=0;
    for (i=0;i<l+l1 && k<l ;i+=2){
            so[i]=ch[k];
            k++;


    }
    j=0;
      for (i=1;i<l+l1 && j<l1 ;i+=2){
            so[i]=sch[j];
            j++;


    }so[l+l1]='\0';
    puts(so);























    return 0;
}
