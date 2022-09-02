#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        vector<int>results;
        for(int i=0;i<n;i++){
            int x=0; int y=i;
            while(x<m){
                if((y==0 and grid[x][y]==-1) or (y==n-1 and grid[x][y]==1)){
                    results.push_back(-1);
                    break;
                }
                if(grid[x][y]==1){
                    if(grid[x][y+1]==-1){
                        results.push_back(-1);
                        break;
                    }else{
                        x+=1; y+=1;
                    }
                }else if(grid[x][y]==-1){
                    if(grid[x][y-1]==1){
                        results.push_back(-1);
                        break;
                    }else{
                        x+=1; y-=1;
                    }
                }               
            }
            if(x==m){
                results.push_back(y);
            }
            
        }
        return results;
    }
};

int main(){

    return 0;
}