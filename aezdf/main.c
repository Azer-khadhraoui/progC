#include <stdio.h>
#include <stdlib.h>

int max(int a,int b);

int main()
{
    int x,y,m;
    printf("x=");
    scanf("%d",&x);
     printf("y=");
    scanf("%d",&y);
    m=max(x,y);
    printf("le max est %d",m);
    return 0;
}

int max(int a,int b){
    if (a<b){
        return b;

    }
    else {
        return a;
    }


}
