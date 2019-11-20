#include<stdio.h>
// s-> liczba setek, d-> liczba dziesiatek, p-> liczba piecdsziesiatek
int main(){
    int kwota,d; 
    printf("Wprowadz kwote: ");
    scanf("%i", &kwota);        
    if (kwota % 10 ==0 && (kwota>30 || kwota==20)){
        for(int s=kwota/100;s>=0;s--){
            for(int p=(kwota-s*100)/50;p>=0;p--){
                d=(kwota-s*100-p*50)/20;
                if(s*100+p*50+d*20==kwota){
                    printf("%i PLN = %i*100 + %i*50 + %i*20\n",kwota,s,p,d);
                }
            }
        }
    }
    else{
        printf("Wprowadziles zla kwote");

    }
    return 0;
}