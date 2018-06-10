#include<stdio.h>
#include<string.h>
void main()
{
    char line[]="hello world", subStr[]="wo";
    int i,j,flag;
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
        if(flag==1)printf("%d ",i);
    }

}
