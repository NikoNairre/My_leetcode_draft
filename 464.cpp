#include<iostream>
#include<unordered_set>
#include<cmath>
using namespace std;
class Solution {
public:
    int visited[1 << 21];
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        if (((maxChoosableInteger) * (1 + maxChoosableInteger) / 2) < desiredTotal) {
            return false;
        }

        return dfs(0,0,maxChoosableInteger,desiredTotal);
    }
    bool dfs(int per_state,int sum_num,int maxChoosableInteger,int desiredTotal){
        if (visited[per_state] == 1) return true;
        if (visited[per_state] == 2) return false;
        for(int x=1;x<=maxChoosableInteger;x++){
            if((1<<x)&per_state){
                continue;
            }
            if(sum_num+x>=desiredTotal){
                visited[per_state] = 1;
                return true;
            }
            if(dfs((1<<x)|per_state,sum_num+x,maxChoosableInteger,desiredTotal)==false){
                visited[per_state] = 1;
                return true;
            }
        }
        visited[per_state] = 2;
        return false;
    }
};
int main(){
    Solution a;
    int n1 = 10;
    int n2 = 18;
    cout<<"hahah"<<endl;
    cout << a.canIWin(n1, n2) << endl;
    return 0;

}