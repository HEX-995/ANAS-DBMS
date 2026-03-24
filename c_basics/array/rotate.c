#include<stdio.h>
int main()
{
    int arr[5]={0,1,2,3,4},f=0;
    for(int i=1; i<5; i++)
    {
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
        {
            f=1;
            break;
        }
        else
        {
            f=0;
        }
    }
    if(f==1)
    {
        printf("Array is rotated");
    }
    else{
        printf("Array is not rotated");
    }
}