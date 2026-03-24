#include <stdio.h>
void sort(int A[], int size)
{
    for (int loop = 0; loop < size; ++loop)
    {
        for (int i = 0; i < size; ++i)
        {
            if (A[i] > A[i + 1])
            {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size-1; i++)
    {
        printf("%d", A[i]);
    }
}
int main()
{
    int size;
    printf("Size: ");
    scanf("%d",&size);
    int A[size];
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&A[i]);
    }

    sort(A, size);
}