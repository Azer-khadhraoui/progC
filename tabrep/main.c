#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[20],n,i,j,maxloc,indice,d[20],s=0,z;
    printf("n=\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("t[%d]= \n",i);
        scanf("%d",&t[i]);
    }
      for(i=0;i<n;i++){
        printf("%d|",t[i]);

    }printf("\n");

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(t[i]==t[j]){
                for(z=j;z<n-1;z++){
                    t[z]=t[z+1];
                }
                n--;
                j--;


            }
        }

        }

printf("tab 2 : \n");
    for(i=0;i<n;i++){
        printf("%d|",t[i]);

    }printf("\n");
    return 0;
}
