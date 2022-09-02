#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    const int next_step[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size();
        vector<vector<int>>pacific = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>>atlantic = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            bfs(i, 0, heights, pacific);
            bfs(i, n - 1, heights, atlantic);
        }
        for (int j = 0; j < n; j++) {
            bfs(0, j, heights, pacific);
            bfs(m - 1, j, heights, atlantic);
        }
        vector<vector<int>>res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] and atlantic[i][j]) {
                    vector<int>r = { i,j };
                    res.emplace_back(r);
                }
            }
        }
        return res;
    }
    void bfs(int x, int y, vector<vector<int>>& heights, vector<vector<int>>& visit) {
        if (visit[x][y] == 1) {
            return;
        }
        int row = heights.size(); int col = heights[0].size();
        queue<pair<int, int>>opqueue;
        opqueue.emplace(make_pair(x, y));
        visit[x][y] = 1;
        while (!opqueue.empty()) {
            int cx = opqueue.front().first; int cy = opqueue.front().second;
            opqueue.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cx + next_step[i][0]; int ny = cy + next_step[i][1];
                if (nx < 0 or nx >= row or ny < 0 or ny >= col or visit[nx][ny] == 1) {
                    continue;
                }
                if (heights[nx][ny] < heights[cx][cy]) {
                    continue;
                }
                visit[nx][ny] = 1;
                opqueue.emplace(make_pair(nx, ny));
            }
        }
    }
};

int main(){
    vector<vector<int>>h= {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution a;
    vector<vector<int>>s=a.pacificAtlantic(h);
    for(auto it:s){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}