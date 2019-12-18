#include<stdio.h>
#include"sorting.h"
#include<stdlib.h>
#include<string.h>
void arr(int x[],int size){
    for(int k=0;k<size;k++){
        printf("%d | ",x[k]);
    }
}
int main(int argc,char* argv[]){
    if (argc==1){
        printf("zad16\nusage: zad16 name\n\nname:\nbubble - for bubble sort\nselection - for selection sort");
        return 0;
    }
    if(strcmp(argv[1],"bubble")!=0 && strcmp(argv[1], "selection")!=0){
        printf("zad16\nusage: zad16 name\n\nname:\nbubble - for bubble sort\nselection - for selection sort");
        return 0;
    }
    int size,b;
    scanf("%i",&size);
    int *x=(int*)malloc(size*sizeof(int));
    for (int i=0;i<size;i++){
        scanf("%i",&x[i]);
    }
    printf("\n");
    arr(x,size);
    if(strcmp(argv[1],"bubble")==0){
        bubble(x,size);
    }
    if(strcmp(argv[1],"selection")==0){
        selection(x,size);
    }
    printf("\n");
    arr(x,size);
}
