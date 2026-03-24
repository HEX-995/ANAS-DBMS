#include<stdio.h>
int main()
{
    int amnt,n1,n2,n3,n4,n5,n6,n7;
    printf("Enter the amount:");
    scanf("%d",&amnt);
    if(amnt%2000!=amnt){
        printf("2000 notes=%d",amnt/2000);
     }
     else if(amnt%500!=amnt){
        printf("500 notes=%d",amnt/500);
     }
     else if(amnt%200!=0){
        printf("200 notes=")
     }
}