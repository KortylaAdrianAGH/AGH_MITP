#include<stdio.h>
void funkcja() {
    static int x=1;
    printf("%i\n", x);
    x++;
}
int main(){
    int n;
    printf("podaj ile razy ma sie wywolac funkcja: ");
    scanf("%i", &n);
    for (int i=n; n>0;n--){
        funkcja();
    }
    return 0;
}