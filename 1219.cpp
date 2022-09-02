#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class Solution {
public:
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int map_lines=grid.size(); int map_cols=grid[0].size();
        int answer=0;
        function<void(int,int,int)> dfs=[&](int x,int y,int all_golds){
            all_golds+=grid[x][y];
            answer=max(answer,all_golds);
            int temp_gold=grid[x][y];
            grid[x][y]=0;
            for(auto item:next_step){
                int next_x=x+item[0];
                int next_y=y+item[1];
                if(next_x<0 or next_x>=map_lines or next_y<0 or next_y>=map_cols){
                    continue;
                }
                if(grid[next_x][next_y]==0){
                    continue;
                }
                dfs(next_x,next_y,all_golds);
            }
            grid[x][y]=temp_gold;
        };
        for(int i=0;i<map_lines;i++){
            for(int j=0;j<map_cols;j++){
                if(grid[i][j]!=0){
                    dfs(i,j,0);
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution a;
    vector<vector<int>>b={{0,6,0},{5,8,7},{0,9,0}};
    vector<vector<int>>c={{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout<<a.getMaximumGold(b)<<endl;
    cout<<a.getMaximumGold(c)<<endl;
    return 0;
}