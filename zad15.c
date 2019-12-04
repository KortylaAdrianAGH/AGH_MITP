#include<stdio.h>
//done
void zamien(int *x,int *y){
    printf("x=%i | y=%i\n",*x,*y);
    int temp =*x;
    *x=*y, *y=temp;
    printf("x=%i | y=%i\n",*x,*y);
}

int main(){
    int x=5,y=7;
    zamien(&x,&y);
    return 0;
}