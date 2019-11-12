#include<stdio.h>
int main() {
  int a,i,j;
  printf("wprowadz wysokosc figury: ");
  scanf("%i", &a);
  // tworzenie górnego boku figury
  printf("\n\t");
  for (i=0;i<a;i++) {
    printf("%%");
  }
  printf("\n");
  // tworzenie bocznych boków figury 
  for (i=1;i<=a-2;i++) {
    printf("\t%%");
    for (j=1; j<=a-2;j++) {  
      printf(" ");
      }    
    printf("%%\n", i);
  }
  // tworzenie dolnego boku figury
  printf("\t");
  for (i=0;i<a;i++) {
    printf("%%");
  }
  printf("\n");
  return(0);
}
