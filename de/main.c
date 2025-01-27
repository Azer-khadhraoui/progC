#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,m[20],s[20];


    printf("n=\n");
    scanf("%d",&n);


    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("donner m[%d][%d]",i,j);
            scanf("%d",&m[i][j]);

        }
    }





         for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d|",m[i][j]);
        }printf("\n");
    }

        for (i=0;i<n;i++){
        s[i]=0;
        for (j=0;j<n;j++){
            s[i]+=m[i][j];
        }
    }




         for (i=0;i<n;i++){
       printf("%d||",s[i]);
    }


    return 0;
}
