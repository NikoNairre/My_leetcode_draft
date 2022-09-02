#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int calArea(vector<vector<int>>& grid,vector<vector<int>>& label,int x,int y){
        int len=grid.size(); int col=grid[0].size();
        queue<pair<int,int>>op;
        op.emplace(make_pair(x,y));
        label[x][y]=1;
        int area=1;
        while(!op.empty()){
            pair<int,int>cur_p=op.front();
            op.pop();
            for(auto next:next_step){
                int nx=cur_p.first+next[0];
                int ny=cur_p.second+next[1];
                if(nx<0 or nx>=len or ny<0 or ny>=col ){
                    continue;
                }
                if(grid[nx][ny]==0 or label[nx][ny]==1){
                    continue;
                }
                op.emplace(make_pair(nx,ny));
                label[nx][ny]=1;
                area++;
            }

        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        vector<vector<int>>visited=vector<vector<int>>(m,vector<int>(n,0));
        int max_area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and visited[i][j]==0){
                    int cur_island_area=calArea(grid,visited,i,j);
                    max_area=max(max_area,cur_island_area);
                }
            }
        }
        return max_area;
    }
};

int main(){

    return 0;
}