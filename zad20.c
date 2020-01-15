#include <string.h>
#include <stdio.h>
#include <stdlib.h>



char *replaceWord(const char *s, const char *oldWord,const char *newWord) {
    char *result;
    int i, count = 0;
    int newWordlen = strlen(newWord);
    int oldWordlen = strlen(oldWord);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldWord) == &s[i])
        {
            count++;

            i += oldWordlen - 1;
        }
    }

    result = (char *)malloc(i + count * (newWordlen - oldWordlen) + 1);

    i = 0;
    while (*s)
    {
        if (strstr(s, oldWord) == s)
        {
            strcpy(&result[i], newWord);
            i += newWordlen;
            s += oldWordlen;
        }
        else
            result[i++] = *s++;
    }
 
    result[i] = '\0';
    return result;
}

int main(int argc,char *argv[]){
	if (argc == 1){
		printf("Usage: zad20 file [-unix|-win]\n");
		return 0;
	}

	if(argc > 1){
		char str[10000];
		FILE *fil;
		char ch0,ch1,f;
		fil = fopen(argv[1],"r");
		if (fil == NULL){
			printf("error\n\r");
			return 0;
		}
		do{
			ch0 = fgetc(fil);
			if(ch0 == '\r'){
				ch1 = fgetc(fil);
				if(ch1 == '\n'){
					f = 'w';
					break;
				}else{
					f = 'm';
					break;
				}
			}else if(ch0=='\n'){
				 ch1 = fgetc(fil);
                                if(ch1 == '\r'){
                                        f = 'w';
                                        break;
                                }else{
                                        f = 'u';
					break;
                                }
			}
		}while(ch0 != EOF);
		if(argc != 3){
			if(f == 'w'){
				printf("%s is a windows file\n",argv[1]);
			}else if(f=='u'){
				printf("%s is a unix file\n",argv[1]);
			}else if (f == 'm'){
				printf("%s is a mac file\n",argv[1]);
			}else{
				printf("no endline marker\n",argv[1]);
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
				else{  
					printf("%s is a windows file - not converted\n\r",argv[1]); 
					sprintf(result,"%s",string);
				}
			}else if(!strcmp(argv[2],"-unix")){
				if(f!='u')result = replaceWord(string,"\r\n","\n");
				else printf("%s is a unix file - not converted\n\r",argv[1]);
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






