#include <stdio.h>

void main(){
    FILE* file;
    FILE* reverse;

    char filename[1024];
    char reversefilename[1024];

    printf("Please enter the normal file name : ");
    scanf("%s" , filename);

    printf("Now enter the file , where you want to reverse the %s containing : " , filename);
    scanf("%s" , reversefilename);

    file = fopen(filename , "r");
    reverse = fopen(reversefilename , "w");

    fseek(file , 0 , SEEK_END);
    int lengthofFile = ftell(file);
    fseek(file , -1 , SEEK_CUR);

    while(lengthofFile > 0){
        char c = fgetc(file);
        fputc(c , reverse);
        fseek(file , -2 , SEEK_CUR);
        --lengthofFile;
    }
}