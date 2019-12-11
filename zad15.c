#include<stdio.h>
//done
void zamien(int *x,int *y){
    int temp =*x;
    *x=*y, *y=temp;
}

int main(){
    int x=5,y=7;
    printf("x=%i | y=%i\n",x,y);
    zamien(&x,&y);
    printf("x=%i | y=%i\n",x,y);
    return 0;
}