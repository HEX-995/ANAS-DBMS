#include<stdio.h>
int main()
{
    int arr[6]={11,21,32,6,50,23},loc_1,loc_2;
    for(int i=0;i<6;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("Write location of the elements you want swap: ");
    scanf("%d %d",&loc_1,&loc_2);
    int temp=0;
    temp=arr[loc_1];
    arr[loc_1]=arr[loc_2];
    arr[loc_2]=temp;
     for(int i=0;i<6;i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}