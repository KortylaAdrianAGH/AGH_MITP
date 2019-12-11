#include<stdio.h>
#include"sorting.h"
void arr(int x[],int size){
    for(int k=0;k<size;k++){
        printf("%d | ",x[k]);
    }
}
int main(int ){
    int size,new;
    scanf("%d", &size);
    int x[size];
    for (int i=0;i<size;i++){
        scanf("%d",&x[i]);
    }
    printf("przeeeeed\n");
    arr(x,size);
    sort(x,size);
    printf("pooooo");
    arr(x,size);
}
