#include"days.h"
#include<stdio.h>
// zmiana kalendarza w 1582 | 5.10-14.10 (dodatkowe 10 dni )  
int day_count(struct DAY d1, struct DAY d2){   
    if((d2.year == 1582 && d2.month ==10 &&(d2.day<14 && d2.day >5)) ||(d1.year == 1582 && d1.month ==10 &&(d1.day<14 && d1.day >5))){
    return 0;
    }
    else {
        int table[12]={31,28,31,30,31,30,31,31,30,31,30,31}; // zwykly 
        int sum1=0, sum2=0,temp=0,p=d2.month-1;
        if (d2.year < d1.year){
            return 0;
        }
        else if(d2.year == d1.year && (d2.month>d1.month || (d2.month == d1.month && d2.day >=d1.day  ))){
            int table[12]={31,28,31,30,31,30,31,31,30,31,30,31};     
            int daydiff1=0,daydiff2=0;
            daydiff1 += d1.day;
            daydiff2 += d2.day;
            for (int i=d2.month-1;i>0;i--){
            if (i==2){
                daydiff2+=1;
            }
            daydiff2+= table[i-1];
            }
            for (int k=d1.month-1;k>0;k--){
            if (k==2){
                daydiff1+=1;
            }
                daydiff1+= table[k-1];
            }
            int daydiff=daydiff2-daydiff1;
        }
        else{
            int leap_year=0;
            int daydiff1 =0,daydiff2=0,daydiff=0;
            int table[12]={31,28,31,30,31,30,31,31,30,31,30,31};     
            for (int i=d2.year-1; i>=d1.year;i--){
                if (i%4==0 && i%100!=0){
                    leap_year +=1;
                }
            } 
            int year_diff = d2.year-d1.year-1;
            daydiff += leap_year *366 + (year_diff -leap_year)*365;         
            daydiff2 += d2.day-1; 
            for (int k=d2.month-2;k>=0;k--){
                daydiff2+=table[k];
            }
            if (d2.year%4==0 && d2.year%100!=0 && d2.month >2){
                daydiff2+=1;
            }

            for (int p=d1.month;p<=12;p++){
                daydiff1+=table[p];
            }
            if((d1.year%4==0 && d1.year%100!=0)&& d1.month<=2){
                daydiff1+=1;
            }
            daydiff1-=d1.day;
            daydiff+= daydiff1+daydiff2;
            return daydiff;  
        }
    }
}