#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int surrounds[9][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>>grids=vector<vector<int>>(n,vector<int>(n,0));
        for(auto lamp:lamps){ grids[lamp[0]][lamp[1]]=1; }
        vector<int>answers;
        for(auto checking:queries){
            bool light=false;
            for(auto lamp:lamps){
                if(grids[lamp[0]][lamp[1]]==0){continue;}
                if(checking[0]==lamp[0] or checking[1]==lamp[1] or abs(checking[0]-lamp[0])==abs(checking[1]-lamp[1])){
                    light=true;
                    break;
                }
            }
            if(light){
                answers.emplace_back(1);
            }else{
                answers.emplace_back(0);
            }
            for(auto item:surrounds){
                int nx=checking[0]+item[0]; int ny=checking[1]+item[1];
                if(nx<0 or nx>=n or ny<0 or ny>=n){continue;}
                if(grids[nx][ny]==1){grids[nx][ny]=0;}
                
            }
        }
        return answers;

    }
};
int main(){
    Solution a;
    int n=5;
    vector<vector<int>> b={{0,0},{4,4}};
    vector<vector<int>> c={{1,1},{1,1}};
    vector<int>result=a.gridIllumination(n,b,c);
    cout<<result.size();
    return 0;
}