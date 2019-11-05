#include <stdio.h>
int main() {
    int table[4],suma;
    printf("Podaj cztery dowolne liczby oddzielajac je za pomoca spacji: ");
    scanf("%i %i %i %i",&table[0],&table[1],&table[2],&table[3]);
    printf("%4i\n", table[0]);
    printf("%4i\n", table[1]);
    printf("%4i\n", table[2]);
    printf("%4i\n", table[3]);
    printf("----\n");
    suma=table[0]+table[1]+table[2]+table[3];
    printf("%4i", suma);
    return(0);
}