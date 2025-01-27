#include <stdio.h>
#include <stdlib.h>

void prem(int x,int *res);
int main()
{
    int n,ind=0,b,t[20],i,j,v[20],p,s,s2;

    b=-1;
    p=-1;
    do{
    printf("x=");
    scanf("%d",&n);
    }while (n==0);
    for (i=n+1;i<n*3 && b==-1;i++){
            prem(i,&s);

            if (s==0){
                b=1;
                j=i;
            }


    }
        for (i=n-1;i>0 && p==-1;i--){
            prem(i,&s2);
            if (s2==0){
                p=1;
                ind=i;
            }


    }
    printf("%d  -- %d ",ind,j);















    return 0;
}

void prem(int x,int *res){
    int t,o;
    t=-1;
    (*res)=0;
    for(o=2;o<(x)-1 && t==-1;o++){
        if((x)%o==0){
            (*res)++;
            t=1;
        }
    }

}
