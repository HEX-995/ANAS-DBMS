#include<stdio.h>
int main()
{
    int long num=123456789258759834759873498759847598437049893485038984778,rev=0;
    while(num!=0){
    rev=rev*10+num%10;
    num=num/10;
    }
    printf("%ld",rev);
    return 0;
}