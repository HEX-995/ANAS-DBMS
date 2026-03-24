#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target)
{
    target=left-right;
    int x, y;
    int mid = (left + right) / 2;

    if (mid == 0)
        return 0;

    x = binarySearch(arr,left,mid-1,target);
    

    y= binarySearch(arr, mid+1, right, target);

    // Search in right half
    return binarySearch(arr, mid + 1, right, target);
}
int main()
{
    int arr[10] = {10, 20, 10, 3030, 40, 20, 10, 30, 20};
}