#include<stdio.h>
struct DAY{
    int day;
    int month;
    int year;
};
struct DAY data1;
struct DAY data2;

int days(struct DAY data1, struct DAY data2){
    // done
    if (data2.year < data1.year){
        printf("zla kolejnosc dat");
        return 0;
    }
    // done
    else if(data2.year == data1.year && (data2.month>data1.month || (data2.month == data1.month && data2.day >=data1.day  ))){
        int table[12]={31,28,31,30,31,30,31,31,30,31,30,31};     
        int daydiff1=0,daydiff2=0,leap_year=0;
        daydiff1 += data1.day;
        daydiff2 += data2.day;
        if(data2.year%4==0 && data2.year%100!=0){
            leap_year=1;
        }
        for (int i=data2.month-1;i>0;i--){
           if (i==2){
               daydiff2+=1;
           }
           daydiff2+= table[i-1];
        }
        for (int k=data1.month-1;k>0;k--){
           if (k==2){
               daydiff1+=1;
           }
            daydiff1+= table[k-1];
        }
        printf("roznica= %i",daydiff2-daydiff1);
    }
    else{
        //zmienne
        printf("blagam licz");
        int leap_year=0;
        int year_diff;
        int daydiff1 =0,daydiff2=0,daydiff=0;
        int table[12]={31,28,31,30,31,30,31,31,30,31,30,31};     
        // policz roki przestepne pomiedzy dwoma latami
        printf("daydiff = %i przzed first 3 last\n", daydiff);
        for (int i=data2.year-1; i>=data1.year;i--){
            if (i%4==0 && i%100!=0){
                leap_year +=1;
            }
        } 
        printf("daydiff = %i, leap year=%i, year_diff=%i przzed first 2last\n", daydiff,leap_year,year_diff);
        // liczenie różnicy w dacie step 1
        daydiff += leap_year *366 + (year_diff -leap_year)*365;
        printf("daydiff = %i przzed first last\n", daydiff);
        // dodawanie pozostalych dni w miesiacu w koncowej dacie
        daydiff2 += data2.day; 
        daydiff1 += data1.day-1;
        printf("daydiff = %i przzed przed last\n", daydiff);
        for (int k=data2.month-1;k>=0;k--){
            daydiff+=table[k];
        }
        printf("daydiff = %i stage przed last\n", daydiff);
        for (int j=data1.month;j>12;j++){
            daydiff+=table[j];
        }
        if (data2.year%4==0 && data2.year%100!=0){
            daydiff+=1;
        }
        if((data1.year%4==0 && data1.year%100!=0)&& data1.month<=2){
            daydiff+=1;
        }
        printf("daydiff = %i stage last\n", daydiff);
        return daydiff;
    }
}

int main(){
    printf("Wprowadz poczatkowa date: ");
    scanf("%i.%i.%i", &data1.day,&data1.month,&data1.year);    
    printf("Wprowadz koncowa date: ");
    scanf("%i.%i.%i", &data2.day,&data2.month,&data2.year); 
    days(data1,data2);  
    
}