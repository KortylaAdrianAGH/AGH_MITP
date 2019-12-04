#include<stdio.h>
#include"point.h"
int main(){  
    struct POINT a,b,c;
    printf("Wprowadz wpolrzedne wierzcholka a: ");
    scanf("%i,%i", &a.x,&a.y);    
    printf("Wprowadz wpolrzedne wierzcholka b: ");
    scanf("%i,%i", &b.x,&b.y);    
    printf("Wprowadz wpolrzedne wierzcholka c: ");
    scanf("%i,%i", &c.x,&c.y);    
    printf("Pole wynosi: %f \n",pole(a,b,c));
    printf("Obwod wynosi: %f \n",obwod(a,b,c));
    return 0;
}