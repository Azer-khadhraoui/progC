#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,s=1,maxloc=1,n,t[20],dern=0;
   printf("donner n");
   scanf("%d",&n);
   for(i=0;i<n;i++){
     printf("donner t[%d]",i);
    scanf("%d",&t[i]);
   }
     for(i=0;i<n;i++){
     printf("%d|",t[i]);

   }printf("\n");
    for(i=0;i<n-1;i++){
    if(t[i]<t[i+1]){
        s++;
        if(s>maxloc){
            maxloc=s;
            dern=i+1;
        }
    }
    else{
        s=1;
    }
   }


   printf("sequence plus longue est %d ",maxloc);
   printf("dernier nombre  se trouve dans %d ",dern);

    return 0;
}
