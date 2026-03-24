#include <stdio.h>
int main() {
int num, a, r=0;
printf("Enter a number: ");
scanf("%d", &num);
a = num;
while (a!=0) {
r = r*10 + (a%10);
a = a/10;
}
printf("Reverse of the number: %d\n", r);
if (num == r) {
printf("%d is a palindrome.\n", num);
}
else {
printf("%d is not a palindrome.\n", num);
}
return 0;
}