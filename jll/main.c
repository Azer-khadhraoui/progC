#include <stdio.h>
#include <stdlib.h>

void sais(int t[],int n);
void aff(int t[],int n);
void inv(int v[],int t[],int n);
int palin(int t[],int n);

int main()
{
    int x,n,ps,t[20],in[20];
    printf("n=");
    scanf("%d",&n);

     sais(t,n);
     aff(t,n);
    inv(in,t,n);
     if (palin(t,n)==1){
        printf("non");
     }
     else {
        printf("palind");
     }



    return 0;
}


void sais(int t[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("t[%d]=",i);
        scanf("%d",&t[i]);
    }
}
void aff(int t[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d|",t[i]);
    }printf("\n");
}

void inv(int v[],int t[],int n){
   int i;
    for (i=0;i<n;i++){
        v[i]=t[n-i-1];
    }
     for (i=0;i<n;i++){
        printf("%d||",v[i]);
    }printf("\n");

}

int palin(int t[],int n){
    int i,w,j;
    i=0;
    j=n-1;
    w=-1;
    while ((i<n) && (j>=0)&& (w==-1)){
        if (t[i]==t[j]){
            i++;
            j--;
        }
        else {
            w=1;
        }
    }
    return w;
}
