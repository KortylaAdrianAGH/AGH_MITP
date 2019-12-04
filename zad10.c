#include<stdio.h>
int main(){
    int a=1,b=1,temp,n; // a i b to kolejne wyrazy ciągu fibonacciego a_1 a_2, temp -> zmienna pomocnicza
    printf("Wpisz n-ty wyraz, ktory chcesz obliczyc: ");
    scanf("%i", &n);
    if (n>2) {
        for (int i=2; i<n;i++){
            temp=a+b;
            a=b;
            b=temp;
        }
        printf("%i elementem ciagu Fibonacciego to: %p",n,temp);
    }
    else {
        printf("%i elementem ciagu Fibonacciego to: 1",n);
    }


    return(0);
}