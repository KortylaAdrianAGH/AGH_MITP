#include <stdio.h>

int main(){
    float a;
    int b;
    printf("Podaj liczbe: ");
    scanf("%f", &a);
    b=(int)a;
    if (a==b){
        printf("calkowita\n");
        if (b%2==0){
            printf("parzysta\n");
        }
        else {
            printf("nieparzysta\n");
        }
    }
    else {
        printf("niecalkowita\n nieparzysta\n");
    }
    return(0);
}
