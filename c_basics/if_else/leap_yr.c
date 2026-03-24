#include<stdio.h>
int main()
{
int yr;
printf("Enter the year:\n");
scanf("%d",&yr);
if(yr%4==0)
{
    printf("it is a leap year\n");
}
else
{
    printf("it is not a leap year\n");
}
}