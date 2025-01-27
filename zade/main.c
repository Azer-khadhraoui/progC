#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[20][20],i,j,n,b,c;
    printf("donner n");
    scanf("%d",&n);
    printf("donner cherhceh");
    scanf("%d",&c);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("dpnner m[%d][%d] ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
       b=1;
       for (i=0;i<n && b==1;i++){

        for (j=0;j<n && b==1;j++){
            if (m[i][j]==c){
                b=-1;
            }
        }
    }
    if(b==-1){
        printf("se trouve");
    }
    else{
        printf("ne se trouve pas");
    }



    return 0;
}
