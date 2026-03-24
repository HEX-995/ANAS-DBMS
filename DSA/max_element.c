#include <stdio.h>
int main()
{
    int A[]={1,2,3,4,5};
    int max=A[0];
    for(int i=0;i<=4;i++)
    {
        if(max<A[i+1])
        {
            max=A[i+1];
        }
    }
    printf("%d",max);
}