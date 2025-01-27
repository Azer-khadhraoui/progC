#include <stdio.h>
#include <stdlib.h>

int main()
{

    int m[22][22],n,nn,s,i,j,ss[22];
    float s1;


    printf("donner nbre i");
    scanf("%d",&n);
    printf("donner nbre j");
    scanf("%d",&nn);



    for (i=0;i<n;i++){
        for (j=0;j<nn;j++){
            printf("donner m[%d][%d]",i,j);
            scanf("%d",&m[i][j]);
        }
    }


s=1;
i=0;
j=0;

while((i<n) && (j<nn) && (s==1)){
        if (j!=i){
            if (m[i][j]==0){
                i++;
                j++;
            }
            else {
                s=0;
            }
        }
        if (j==i){
                if (m[i][j]==1){
                i++;
                j++;
            }
            else {
                s=0;
            }

        }

}
if (s==0){
    printf(" pas identite \n");
}
else {
    printf("identite\n");
}








      for (i=0;i<n;i++){
        for (j=0;j<nn;j++){
            if (m[i][j]>s1){



            printf("%d||",m[i][j]);

        }
    }printf("\n");




}


    return 0;
}
