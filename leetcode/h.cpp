// class Solution {
// public:
// vector<vector<int>> answer;
// set<vector<int>>st;
// void goal(vector<int>& candidates, int target,int sum,vector<int>&subset,int i){
//     if(sum==target){
//         st.insert(subset);
//         return;
//     }
//     if(sum>target||i>=candidates.size()){
//         return;
//     }
//     subset.push_back(candidates[i]);
//     goal(candidates,target,sum+candidates[i],subset,i+1);
//     subset.pop_back();
//     goal(candidates,target,sum,subset,i+1);
// }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<int>subset={};
//         goal(candidates,target,0,subset,0);
//         answer.assign(st.begin(),st.end());
//         return answer;
//     }
// };
   