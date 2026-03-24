#include <stdio.h>
int main()
{
    char s[] = "dilshad", temp;
    int start = 0, end = 6;
    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    printf("%s", s);
}
