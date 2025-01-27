#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char p[20],ch[20][20],m[20];
    int i,n,j,max,pos,indmin,a[20],nb,choix,trv;


 printf("donner n ");
    scanf("%d",&n);
for (i=0;i<n;i++){
    printf("donner a[%d] ",i);
    scanf("%d",&a[i]);

}
 printf("donner pos ");
    scanf("%d",&pos);
     printf("donner nombre ajoute ");
    scanf("%d",&nb);

for (i=n-1;i>pos-1;i--){
        a[i+1]=a[i];


}n++;
a[pos]=nb;


for (i=0;i<n;i++){
    printf("%d| ",a[i]);


}





    return 0;
}
