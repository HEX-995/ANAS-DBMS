#include<bits/stdc++.h>
using namespace std;
int main(){
//     map<int,vector<int>>element;
//     element[1]={10,11};
//     element[2]={20,21};
//     for(auto p:element){
//         if(p.first==1){
//             p.second.push_back(12);
//         }
//     }
//     cout<< element[1];
// }
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> element;
        vector<int> arr;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                int sum = i + j;
                element[sum].push_back(mat[i][j]);
            }
        }

        for(auto &p : element){
            if(p.first % 2 == 0){
                // even diagonal -> reverse order
                for(int k = p.second.size() - 1; k >= 0; k--){
                    arr.push_back(p.second[k]);
                }
            } else {
                // odd diagonal -> normal order
                for(int k = 0; k < p.second.size(); k++){
                    arr.push_back(p.second[k]);
                }
            }
        }

        return arr;
    }
};
} 