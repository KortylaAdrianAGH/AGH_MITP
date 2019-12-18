#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){
        if(argc==1){
                printf("\nusage:zad 20 [-unix|win] file\n\n");
        }
        else if(!strcmp(argv[1],"-unix")){
                FILE *plik=fopen(argv[2], "r+");
                if(plik==NULL){
                        printf("\nNULL\n");
                }
                char znak;
                while((feof(plik)==0)){
                        fscanf(plik,"%c",&znak);
                        if(((int)znak==13)){
                                fseek(plik,-1,1);
                                fprintf(plik," ");
                        }
                }
                fclose(plik);
                printf("file: %s succesfully converted to unix format\n",argv[2]);
                }
        else if(!strcmp(argv[1],"-win")){
                FILE *plik=fopen(argv[2],"r+");
                FILE *plik2=fopen("xxx.c","w");
                char znak;
                int abort =0;
                while(feof(plik)==0){
                        fscanf(plik, "%c", &znak);
                        if((int)znak==10){
                                fprintf(plik2,"%c",13);
                        }
                        if((int)znak==10){
                                fprintf(plik2,"%c",13);
                        }
                        fprintf(plik2,"%c",znak);
                }
                if(abort==0){
                        fseek(plik,0,0);
                        fseek(plik2,0,0);
                        fclose(plik);
                        fclose(plik2);
                        FILE *p3=fopen(argv[2],"w");
                        FILE *p4=fopen("xxx.c","r");
                        while(feof(plik2)==0){
                                fscanf(p4,"%c",&znak);
                                fprintf(p3,"%c", znak);
                        }
                        fclose(p3);
                        fclose(p4);
                        printf("file: %s succesfully converted to windows format\n",argv[2]);
                }
                else{
                        printf("%s is a windows file - not converted\n",argv[2]);
                }
        }
        else{
                FILE *plik=fopen(argv[1],"r");
                char znak;
                int type=0;
                while(feof(plik)==0){
                        fscanf(plik,"%c",&znak);
                        if((int)znak==13){
                                type=1;
                                break;
                        }
                }
                fclose(plik);
                if(type==0){
                        printf("%s is an unix file\n",argv[1]);
                }
                else{
                        printf("%s is a windows file\n",argv[1]);
                }
        }
        return 0;
}