#include <stdio.h>

// Function to reverse the number
int reverseNumber(int n, int rev) {
    if (n == 0)
        return rev;
    else
        return reverseNumber(n / 10, rev * 10 + n % 10);
}

// Function to check if the number is a palindrome
int isPalindrome(int n) {
    return n == reverseNumber(n, 0);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);

    return 0;
}