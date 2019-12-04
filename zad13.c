//done
#include<stdio.h>
#include "days.h"
int main(){  
    struct DAY d1, d2;
    printf("Wprowadz poczatkowa date: ");
    scanf("%i.%i.%i", &d1.day,&d1.month,&d1.year);    
    printf("Wprowadz koncowa date: ");
    scanf("%i.%i.%i", &d2.day,&d2.month,&d2.year); 
    printf("pomiedzy datami jest %i dni roznicy" ,day_count(d1,d2));
    return 0;
}
