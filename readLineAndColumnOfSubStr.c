#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define LINE_SIZE 80
int main(void)
{
    FILE * fp;
    char line[LINE_SIZE],subStr[LINE_SIZE];
    int line_number=0,l=0,i,j,flag;
    char c;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    printf("enter substring");
    scanf("%s",subStr);
    do
    {
        //read by line
        l=0;
        memset(line,'\0',sizeof(line));
        while((c = fgetc(fp)) != EOF)
        {
            if(c=='\n')break;
            line[l++]=(char)c;
        }
        line[l]='\0';
        //printf("%s\n",line);
        for(i=0;i<strlen(line)-strlen(subStr);i++)
        {
            flag=1;
            for(j=0;j<strlen(subStr);j++)
            {
                if(line[i+j]!=subStr[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)printf("line_number: %d column_number: %d \n",line_number,i);
        }
        line_number++;
    }while(c!=EOF);
    fclose(fp);
    exit(EXIT_SUCCESS);
}
