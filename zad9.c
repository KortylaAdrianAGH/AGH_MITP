#include<stdio.h>
int main() {
    int k,n,i,j,space; 
    printf("wprowadz wysokosc piramidy: ");
    scanf("%i", &n);
    for (i=0;i<=n;i++){
        printf("\t");
        for(space=0;space<n-i;space++){
            printf(" ");
        }   
        for(j=0;j<i;j++){
            printf("%%");
        }
        for (k=0;k<i-1;k++){
            printf("%%",k,i);
        } 
    printf("\n");
    }
}

