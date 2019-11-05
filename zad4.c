#include <stdio.h>
#include<math.h>

int main(){
    float a;
    printf("Podaj liczbe: ");
    scanf("%f", &a);
    if (fmod(a,2)==0) {
        printf("liczba jest parzysta\n");
    }
    else{
        printf("liczba nie jest parzysta\n");
    }
    if(fmod(a,1)==0){
        printf("liczba jest calkowita");

    }
    else {
        printf("liczba nie jest calkowita");
    }
    return(0);
}
