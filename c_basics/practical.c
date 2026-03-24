#include<stdio.h>
#include<math.h>
int main(){
float a,b,c; float Discriminant;
printf("Enter values of a,b,c for ax^2+bx+c \n");
printf("a= ");
scanf("%f",&a);
printf("b= ");
scanf("%f",&b);
printf("c= ");
scanf("%f",&c);
Discriminant=((b*b)-(4*a*c));
if(Discriminant>0){
printf("Root 1 =%f\n",(-b+sqrt(Discriminant))/(2*a));
printf("Root 2 =%f\n",(-b-sqrt(Discriminant))/(2*a));
}
else if(Discriminant==0){
printf("Root 1 =%f\n",(-b)/(2*a));
printf("Root 2 =%f\n",(-b)/(2*a));
}
else{
printf("Roots are imaginary.");
}
}