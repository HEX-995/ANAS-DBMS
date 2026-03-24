#include<stdio.h>
int main()
{
float cp,sp,pr;
printf("Enter selling price of the item:\n");
scanf("%f",&sp);
printf("Enter cost price of the item:\n");
scanf("%f",&cp);
 pr=((sp-cp)/cp)*100;
if(sp>cp)
{
    printf("profit of %f percent was made on this item\n",pr);
}
else if(cp>sp)
{
    printf("loss of %f percent was made on this item",-pr);
}
else{
    printf("no profit or loss was made on this item");
}
}