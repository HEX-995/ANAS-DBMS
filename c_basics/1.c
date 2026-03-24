#include<stdio.h>
int main(){
int x;
printf ("Enter a number: ");
scanf("%d",&x);
int count=0 ;
int y =x;
while(y>0){
count++;
y/=10;
printf("%d",count);
}
printf ("\n no of digits in %d is %d",x,count);
}