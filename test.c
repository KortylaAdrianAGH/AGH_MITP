/* (float) x ---> converting the int to float; 
x+=1 ---> adding 1 to x 
x-=1 ---> substracting 1 from x
x*=2 -----------||-------------
x/=2 -----------||-------------
x%=2 -----------||-------------
x = z--;   assign 3 to x, then decrement z to 2 
y = 3
x = ++y  increment y to 4, then assign 4 to x 

y = (x >= 5) ?  5 : x;
 This is equivalent to:
  if (x >= 5)
    y = 5;
  else
    y = x;

*/

#include<stdio.h>
int main() {
  int a,i,j;
  printf("wprowadz wysokosc trojkata: ");
  scanf("%i", &a);
  i=0;
  for (i=0;i<a;i++) {
    for (j=0; j<=i;j++) {   
      printf("%% ");
    }
  printf("%i \n", i);
  }
  return(0);


}

