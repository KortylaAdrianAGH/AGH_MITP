#include <stdio.h>
#include<math.h>
int main(){
    int a;
    float b;
    printf("Podaj temperature w stopniach celcjusza : ");
    scanf("%i", &a);
    b=a*1.8+32;
    // obcinanie zer, gdy b - liczba calkowita
    if (fmod(b,1)==0) {
        int c;
        c=(int)b;
        printf("%i [F]",c);    
    }
    else {
        printf("%f [F]",b);
    }
    return(0);
}