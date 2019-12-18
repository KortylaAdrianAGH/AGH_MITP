#define MAX_FILE_NAME 100 
  
void linecounter() 
{ 
    FILE *fp; 
    int count = 0,count1=0;  
    char filename[MAX_FILE_NAME]; 
    char c;  // To store a character read from file 
  
    // Get file name from user. The file should be 
    // either in current folder or complete path should be provided 
    printf("Enter file name: "); 
    scanf("%s", filename); 
  
    // Open the file 
    fp = fopen(filename, "r"); 
  
    // Check if file exists 
    if (fp == NULL){ 
        printf("File ""%s"" does not exist! ", filename); 
        return 0; 
    } 
  
    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)){ 
        count1+=1;
        if (c == '\n'){ 
            count = count + 1; 
            count1=0;
        }
    }
    if (count1>0){
        count+=1;
    }
    else if (count>0){
        count+=1;
    } 
    fclose(fp);  
} 