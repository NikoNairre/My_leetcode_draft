//DFS
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    vector<vector<int>>visit;
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        visit=vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int j=1;j<n-1;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(visit[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 or row>=m or col<0 or col>=n or grid[row][col]==0 or visit[row][col]==1){
            return;
        }
        visit[row][col]=1;
        for(auto next:next_step){
            int nx=row+next[0]; int ny=col+next[1];
            dfs(grid,nx,ny);
        }
    }
};

int main(){
    Solution a;
    vector<vector<int>>b={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<a.numEnclaves(b);
    return 0;
}