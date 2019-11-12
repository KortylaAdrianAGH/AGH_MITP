#include<stdio.h>
int main(){
    int n;
    printf("Wpisz n-ty wyraz, który chcesz obliczyc: ");
    scanf("%i", &n);
    int table[n];
    table[0]=1, table[1]=1;
    //printf("%i, %i   hehe",table[0],table[1]);
    if (n>2){
        for (int i=2;i<n;i++){
            table[i]=table[i-1]+table[i-2];
            //printf("%d, %i\n", table[i], i);
        }  
        printf("%i elementem ciągu Fibonacciego to: tablica[%d]",n,temp);  
    }
    printf("%d 2, %d 3 %d 4 ",table[2],table[3],table[4]);
    /*else {
        printf("%d",table[n-1]);
    }
    */
    return(0);
}
