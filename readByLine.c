#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define LINE_SIZE 80
int main(void)
{
    FILE * fp;
    char line[LINE_SIZE];
    int line_position=0;
    char c;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    do
    {
        //read by line
        line_position=0;
        memset(line,'\0',sizeof(line));
        while((c = fgetc(fp)) != EOF)
        {
            if(c=='\n')break;
            line[line_position++]=(char)c;
        }
        line[line_position]='\0';
        printf("%s\n",line);
    }while(c!=EOF);
    fclose(fp);
    exit(EXIT_SUCCESS);
}
