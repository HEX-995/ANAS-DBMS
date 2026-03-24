//implementation of sjf scheduling by using function
#include<bits/stdc++.h>
using namespace std;
struct package{
    int at,bt,ct,tat,wt,pid;
};
bool compare(package p1,package p2){
    return p1.bt<p2.bt;
}   
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    package p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter arrival time and burst time of process "<<i+1<<": ";
        cin>>p[i].at>>p[i].bt;
        p[i].pid= kjn