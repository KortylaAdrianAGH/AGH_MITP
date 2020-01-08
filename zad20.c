#include <string.h>
#include <stdio.h>
#include <stdlib.h>



char *replaceWord(const char *s, const char *oldWord,const char *newWordW) {
    char *result;
    int i, count = 0;
    int newWordWlen = strlen(newWordW);
    int oldWordlen = strlen(oldWord);

    for (i = 0; s[i] != '\0'; i++){
        if (strstr(&s[i], oldWord) == &s[i]){
            count++;
            i += oldWordlen - 1;
        }
    }

    result = (char *)malloc(i + count * (newWordWlen - oldWordlen) + 1);

    i = 0;
    while (*s){
        if (strstr(s, oldWord) == s){
            strcpy(&result[i], newWordW);
            i += newWordWlen;
            s += oldWordlen;
        }
        else{  //wciecia
            result[i++] = *s++;
    	}
	}
    result[i] = '\0';
    return result;
}

int main(int argc,char *argv[]){
	if (argc == 1){
		printf("Usage: zad20 file [-unix|-win]\n\r");
		return 0;
	}

	if(argc > 1){
		char str[10000];
		FILE *fil;
		char char0,char1,f;
		fil = fopen(argv[1],"r");
		if (fil == NULL){
			printf("error\n\r");
			return 0;
		}
		do{
			char0 = fgetc(fil);
			if(char0 == '\r'){
				char1 = fgetc(fil);
				if(char1 == '\n'){
					f = 'w';
					break;
				}
				else{
					f = 'm';
					break;
				}
			}
			else if(char0=='\n'){
				 char1 = fgetc(fil);
                                if(char1 == '\r'){
                                        f = 'w';
                                        break;
                                }
								else{
                                        f = 'u';
					break;
                                }
			}
		}while(char0 != EOF);
		if(argc != 3){
			if(f == 'w'){
				printf("%s is a windows file\n\r",argv[1]);
			}else if(f=='u'){
				printf("%s is a unix file\n\r",argv[1]);
			}else if (f == 'm'){
				printf("%s is a mac file\n\r",argv[1]);
			}else{
				printf("no endline marker\n\r",argv[1]);
			}
			fclose(fil);
		}else{
			fseek(fil, 0, SEEK_END);
			long fsize = ftell(fil);
			fseek(fil, 0, SEEK_SET);
			char *string = malloc(fsize + 1);
			fread(string, 1, fsize, fil);
			string[fsize] = 0;
			fclose(fil);
			fil = fopen(argv[1],"w");
			char *result;
			if(!strcmp(argv[2],"-win")){
				if(f!='w')result = replaceWord(string,"\n","\r\n");
				else  printf("%s is a windows file - not converted\n",argv[1]);
			}else if(!strcmp(argv[2],"-unix")){
				if(f!='u')result = replaceWord(string,"\r\n","\n");
				else printf("%s is a unix file - not converted\n",argv[1]);
			}
			else{
				fclose(fil);
				return 0;
			}
			fputs(result,fil);
			fclose(fil);
		}
	}
}






