#include <stdio.h>

void main()
{
    FILE* read;
    FILE* copy;
    char file[1024];
    char reverse[1024];

    printf("File to reverse : ");
    scanf("%s" , file);

    printf("New file : ");
    scanf("%s" , reverse);

    read = fopen(file , "r");

    copy = fopen(reverse , "w");

    if(read == NULL || copy == NULL)
    {
        printf("Error while opening files\n");
        return;
    } 

    fseek(read , 0 , SEEK_END);
    int length = ftell(read);
    fseek(read , -1 , SEEK_CUR);

    while(length > 0)
    {
        char ch = 0;
        ch = fgetc(read);
        fputc(ch , copy);
        fseek(read , -2 , SEEK_CUR);
        --length;
    }

    fclose(read);
    fclose(copy);
    return;
}