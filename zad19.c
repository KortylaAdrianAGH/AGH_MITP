#include <stdio.h>   
int main(int argc,char* argv[]){ 
    if (argc==1){
        printf("zad19\nusage: zad19 filename\n\nfilename:\nname - for file inside same directory\npath to the file - for files outside the directory\n");
        return 0;
    }
    FILE *fp; 
    int count = 0,count1=0;  // ilosc lini 
    char c;  
    fp = fopen(argv[1], "r"); 
    // sprawdzanie czy program istnieje  
    if (fp == NULL){ 
        printf("File ""%s"" does not exist!\n ", argv[1]); 
        return 0; 
    } 
    for (c = fgetc(fp); c != EOF; c = fgetc(fp)){ 
        count1+=1;
        if (c == '\n'){ 
            count = count + 1; 
            count1=0;
        }
    }
    if (count1>0){
        count+=1;
    }
    // zamykanie programu
    fclose(fp); 
    printf("The file %s has %d lines\n ", argv[1], count);  
    return 0; 
} 