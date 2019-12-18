int main(){
    if (argc==1){
        printf("zad16\nusage: zad16 name\n\nname:\nbubble - for bubble sort\nselection - for selection sort");
        return 0;
    }
    if(strcmp(argv[1],"bubble")!=0 && strcmp(argv[1], "selection")!=0 && strcmp(argv[1],"string")!=0){
        printf("zad16\nusage: zad16 name\n\nname:\nbubble - for bubble sort\nselection - for selection sort");
        return 0;
    }    
    int count;
    char str[100][100],temp[25];
    printf("How many strings u are going to enter?: ");
    scanf("%d",&count);
    printf("Enter Strings one by one: ");
    for(int i=0;i<=count;i++)
      gets(str[i]);