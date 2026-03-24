#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
// vector<vector<int>> answer;
// void goal(vector<int>& candidates, int target,int sum,vector<int>subset,int i){
//     if(sum==target){
//         answer.push_back(subset);
//         return;
//     }
//     if(sum>target||i>=candidates.size()){
//         return;
//     }
//     subset.push_back(candidates[i]);
//     goal(candidates,target,sum+candidates[i],subset,i);
//     subset.pop_back();
//     goal(candidates,target,sum+candidates[i],subset,i+1);
// }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         goal(candidates,target,0,{},0);
//         return answer;
//     }
// };


// class Solution {
// public:
// vector<vector<int>> answer;
// void goal(vector<int>& candidates, int target,int sum,vector<int>subset,int i){
//     if(sum==target){
//         answer.push_back(subset);
//         return;
//     }
//     if(sum>target||i>=candidates.size()){
//         return;
//     }
//     subset.push_back(candidates[i]);
//     goal(candidates,target,sum+candidates[i],subset,i);
//     subset.pop_back();
//     goal(candidates,target,sum,subset,i+1);
// }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         goal(candidates,target,0,{},0);
//         return answer;
//     }
// };

class Solution {
public:
vector<vector<int>> answer;
void goal(vector<int>& candidates, int target,vector<int>&subset,int idx){
    if(target==0){
        answer.push_back(subset);
        return;
    }
    for(int i=idx;i<candidates.size();i++){
        if(i>idx &&candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target){
            break;
        }
        subset.push_back(candidates[i]);
        goal(candidates,target-candidates[i],subset,i+1);
        subset.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        goal(candidates,target,subset,0);
        return answer;
    }
};
   