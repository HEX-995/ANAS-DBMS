#include<stdio.h>
void rotate(int* nums, int numsSize, int k) {
    int i,temp,count=0;
    temp=nums[numsSize-1];
    while(count!=k){
        for(int i=0;i<numsSize-2;i++){
            nums[i+1]=nums[i];
        }
        nums[0]=temp;
        count++;
    }
int main(){
    
}