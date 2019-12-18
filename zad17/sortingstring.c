#include<stdio.h>
#include<string.h>
int main(){
   int count;
   char str[100][100],temp[25];
   printf("How many strings u are going to enter?: ");
   scanf("%d",&count);

   printf("Enter Strings one by one: ");
   for(int i=0;i<=count;i++)
      gets(str[i]);
   for(int i=0;i<=count;i++)
      for(int j=i+1;j<=count;j++){
         if(strcmp(str[i],str[j])>0){
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
         }
      }
   printf("\nOrder of Sorted Strings:");
   for(int i=0;i<=count;i++)
      printf("%s\n",str[i]);
   return 0;
}