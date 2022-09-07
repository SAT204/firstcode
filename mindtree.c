#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    char str[50],cpy_str[50];
    scanf("%s",&str);
    strcpy(cpy_str,str);
    strrev(cpy_str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i] == cpy_str[i])
        {
            count++;
        }
    }
    printf("%s",cpy_str);
    printf("\n");
    printf("%d",count);
    return 0;
}
