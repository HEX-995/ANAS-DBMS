#include <stdio.h>


int fact(int x) {
    if(x==1) return 1;
    int factxm1= fact(x-1);
    int factx = factxm1*x;
}

int main() {
    int n;
    printf("Enter The Number : ");
    scanf("%d", &n);

    int a=fact(n);
    printf("%d", a);
    return 0;
}