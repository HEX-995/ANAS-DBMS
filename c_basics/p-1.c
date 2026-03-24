#include<stdio.h>
/*int main(){
    int s=0,n;
    printf("enter the limit:\n");
    scanf("%d",&n);
    for(int i=1,j=n; i<=n && j>=1;j--,i++){
        s=s+i;
        printf("%d\n",j);
    }
    printf("\n%d\n",s);
    
    return 0;
}*/
/*int main(){
    int i=0,n;
    printf("enter the value:");
    scanf("%d",&n);
    while(i<=n){
    printf("%d\n",i);
    i++;
    }
    return 0;
}*/
/*int main(){
    int i=1,sum=0,n;
    printf("enter the limit:\n");
    scanf("%d",&n);
    do{
        sum=sum+i;
        i++;
    }
    while(i<=n);
  printf("%d\n",sum);
    return 0;
}*/
/*int main(){
    int n;
    printf("enter the no:\n");
    scanf("%d",&n);
    for(int i=1; i<=10; i++){
        if(i==6){
            break;
        }
        int y=i*n;
        printf("%d\n",y);
    }
    
    return 0;
}*/
int main(){
    int n;
    printf("enter the no:\n");
    scanf("%d",&n);
    if(n%2==1){
     printf("please enter an even no.");
    }
    else
    {

    for(int i=1; i<=10; i++){
        if(i==6){
            break;
        }
        int y=i*n;
        printf("%dx%d=%d\n",n,i,y);
    }
    }
    return 0;
}