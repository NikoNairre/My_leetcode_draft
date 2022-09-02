//BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    vector<vector<int>>visit;
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        visit=vector<vector<int>>(m,vector<int>(n,0));
        queue<pair<int,int>> op_queue;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                op_queue.emplace(make_pair(i,0));
                visit[i][0]=1;
            }
            if(grid[i][n-1]==1){
                op_queue.emplace(make_pair(i,n-1));
                visit[i][n-1]=1;                
            }
        }
        for(int j=1;j<n-1;j++){
            if(grid[0][j]==1){
                op_queue.emplace(make_pair(0,j));
                visit[0][j]=1;
            }
            if(grid[m-1][j]==1){
                op_queue.emplace(make_pair(m-1,j));
                visit[m-1][j]=1;
            }
        }
        while (!op_queue.empty()){
            pair<int,int>cur_point=op_queue.front();
            op_queue.pop();
            int x=cur_point.first; int y=cur_point.second;
            for(auto next:next_step){
                int nx=x+next[0]; int ny=y+next[1];
                if(nx<0 or nx>=m or ny<0 or ny>=n or grid[nx][ny]==0 or visit[nx][ny]==1){
                    continue;
                }
                visit[nx][ny]=1;
                op_queue.emplace(make_pair(nx,ny));
            }
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==1 and visit[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution a;
    vector<vector<int>>b={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<a.numEnclaves(b);
    return 0;
}