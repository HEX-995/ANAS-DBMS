#include<stdio.h>
int main()
{
    int arr[6]={11,21,32,6,50,23};
    int max=arr[0];
    for(int i=0;i<5;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("%d is the maximum element in the given array. ",max);
    return 0;
}