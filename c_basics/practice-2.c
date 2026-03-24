#include<stdio.h>
int main(){
    int a=(int) 2.345;
    int b= 3;
    int c= 8;
    int r=7;
    printf("%d",(a+b*c+r-a/a+b)==35 && !(4*5==20));
}