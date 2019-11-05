#include <stdio.h>
int main() {
    float a,b,d;
    char c;
    printf("Podaj wyrazenie: ");
    scanf("%f%c%f", &a, &c, &b );
    switch(c)
    {
        case '+':
            d=a+b;
            if ((int)d==d) {
                printf("%i", (int)d);
            }
            else {
                printf("%f",d);
            }
            break;
        case '-':   
            d=a-b; 
            if ((int)d==d) {
                printf("%i", (int)d);
            }         
            else {
                printf("%f",d);
            }
            break;
        case '*':
            d=a*b;
            if ((int)d==d) {
                printf("%i", (int)d);
            }
            else {
                printf("%f",d);
            }
            break;
    
        case '/':
            d=a/b;
            if ((int)d==d) {
                printf("%i", (int)d);
            }
            else {
                printf("%f",d);
            }
            break;
    }
    return(0);
}