#include <stdio.h>
int main(){
    float a,b;
    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &a);
    printf("Podaj druga liczbe: ");
    scanf("%f", &b);
    if (a>b) {
        printf("Pierwsza podana liczba jest wieksza (%f)", a);
    }
    else if (b>a){
        printf("Druga podana liczba jest wieksza (%f)", b);
    }
    else { 
        printf("Obydwie podane liczby sa rowne (%f)", a);
    }
    return(0);
}