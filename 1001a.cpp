#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int surrounds[9][2]={{0,0},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_set<long long>open_positions;
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        unordered_map<int,int>main_digs;
        unordered_map<int,int>sub_digs;
        for(auto lamp:lamps){
            if(open_positions.find((long long)lamp[0]*n+lamp[1])!=open_positions.end()){continue;}
            open_positions.emplace((long long)lamp[0]*n+lamp[1]);
            rows[lamp[0]]++;
            cols[lamp[1]]++;
            main_digs[lamp[0]-lamp[1]]++;
            sub_digs[lamp[0]+lamp[1]]++;
        }
        vector<int>answers;
        for(auto checking:queries){
            int x=checking[0]; int y=checking[1];
            if(rows[x] or cols[y] or main_digs[x-y] or sub_digs[x+y]){
                answers.emplace_back(1);
            }else{
                answers.emplace_back(0);
            }
            for(auto next:surrounds){
                int nx=x+next[0]; int ny=y+next[1];
                if(nx<0 or nx>=n or ny<0 or ny>=n){continue;}
                if(open_positions.find((long long)nx*n+ny)!=open_positions.end()){
                    open_positions.erase((long long)nx*n+ny);
                    rows[nx]--;
                    cols[ny]--;
                    main_digs[nx-ny]--;
                    sub_digs[nx+ny]--;
                }
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