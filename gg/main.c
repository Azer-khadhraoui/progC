#include <stdio.h>
#include <stdlib.h>

int ps(int m[],int t[],int z);




int main()
{
    int l,z,m[20],t[20],i,j,ss;
    printf("z=");
    scanf("%d",&z);


    for(j=0;j<z;j++){
        printf("m[%d]=",j);
        scanf("%d",&m[j]);
    }

    for(j=0;j<z;j++){
        printf("t[%d]=",j);
        scanf("%d",&t[j]);
    }

    for(j=0;j<z;j++){
        printf("%d|",t[j]);

    }printf("\n");
      for(j=0;j<z;j++){
        printf("%d|",m[j]);

    }printf("\n");


printf("%d",ps(m,t,z));

    return 0;
}
int ps(int m[],int t[],int z){
   int i,j,s;
   s=0;

    for(j=0;j<z;j++){
        s=s+m[j]*t[j];
    }




   return s;
}
