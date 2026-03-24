#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream sourcefile("source.txt");
    if(!sourcefile){
        cout<<"error: source txt not found"<<endl;
        return 1; 
    }
    ofstream destfile("dest.txt");
    if(!destfile){
        cout<<"error: destination txt not found"<<endl;
    }
    string line;
    while(getline(sourcefile,line)){
        destfile<<line<<endl;
    }
    cout<<"file copied successfully"<<endl;
    sourcefile.close();
    destfile.close();
    return 0;
}