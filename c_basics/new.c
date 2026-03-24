#include<stdio.h>
#include<math.h>
int main()
{
int ori,a,sum=0,num,count=0,;
printf("Enter the no: \n");
scanf("%d",&num);
ori=num;
while(num!=0){
    num=num/10;
    count++;
}
num=ori;
while(num>=1){
    a=num%10;
    sum+=pow(a,count);
    num=num/10;
}
if(sum==ori){
    printf("it is an armstrong no.");
}
else{
    printf("it is not an armstrong no.");
}
return 0;

}