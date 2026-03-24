#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<vector<char>>&board,string word,int i, int j, int m, int n, int idx){
        int temp;
        if(idx==word.length()-1){
            return true;
        }
        if(board[i][j]!=word[idx]||i>m||j>n||board[i][j]=='!'||i<0||j<0){
            return false;
        }
        temp=board[i][j];
        board[i][j]='!';
        int top=search(board,word,i-1,j,m,n,idx+1);
        int bottom=search(board,word,i+1,j,m,n,idx+1);
        int left=search(board,word,i,j-1,m,n,idx+1);
        int right=search(board,word,i,j+1,m,n,idx+1);
        return top||bottom||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,m,n,idx=0;
        m=board.size()-1;
        n=board[0].size()-1;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]==word[idx]){
                    return search(board,word,i,j,m,n,idx);
                }
            }
        }
        return false;
    }
};
int main(){
    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    Solution obj;
    cout<<obj.exist(board,word);
}