#include <stdio.h>
int main(){
    float b;
    printf("Podaj temperature w stopniach celcjusza : ");
    scanf("%f", &b);
    int a=b*1.8+32;
    a=(int)a; 
    printf("%i",a);
    return(0);
}