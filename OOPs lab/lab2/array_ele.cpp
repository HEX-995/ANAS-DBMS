#include<iostream>
using namespace std;
int main(){
    int oneD[4] = {1,2,3,4};
    cout<<"Accessing one D elements" <<endl;
    for(int i = 0; i < 4; i++){
        cout<<oneD[i]<<" ";
        cout<<*(oneD + i)<<endl;
    }


    int twoD[2][2] = {{1,2}, {3,4}};
    cout<<endl<<"Accessing two D elements" <<endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout<<twoD[i][j]<<" ";
            cout<<*(*(twoD+ i)+j)<<endl;
        }
    }

    int threeD[2][2][2] = {
        {{1,2}, {3,4}},
        {{5,6}, {7,8}},
     };
    cout<<endl<<"Accessing three D elements"<<endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                cout<<threeD[i][j][k]<<" ";
                cout<<*(*(*(threeD + i) + j) + k)<<endl;
            }
        }
    }

    return 0;
}