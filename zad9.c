#include<stdio.h>
int main() {
    int n,i,j,space; 
    printf("wprowadz wysokosc piramidy: ");
    scanf("%i", &n);
    for (i=0;i<=n;i++){
        printf("\t");
        for(space=0;space<n-i;space++){
            printf(" ");
        }   
        for (j=0;j<2*i-1;j++){
            printf("%%");
        } 
    printf("\n");
    }
}

