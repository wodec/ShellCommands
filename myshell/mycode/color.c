#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int main (int argc, char **argv)  
{
    char buffer[1000];
    int cnt = 0;
    printf("输出exit退出！\n");
    scanf("%s",buffer);
//    printf("%d",strcmp(buffer,"exit"));
    while(strcmp(buffer,"exit")!=0)
   {
    if((cnt)%4==0)
    printf ("\033[31m%s\033[0m\n",buffer); 
    else if((cnt)%5==1)
    printf ("\033[32m%s\033[0m\n",buffer);  
    else if((cnt)%5==2)
    printf ("\033[33m%s\033[0m\n",buffer);
    else
    printf ("\033[34m%s\033[0m\n",buffer);
    cnt++;
    scanf("%s",buffer);
   }
   printf("\033[0m\n");
   return 0;
}  
