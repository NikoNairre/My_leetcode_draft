#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp=vector<int>(9,0);
        dp[0]=1;
        for(int i=1;i<dp.size();i++){
            static int cases=9;
            dp[i]=dp[i-1]+cases;
            cases*=10-i;
        }
        return dp[n];
    }
};
int main(){
    int a=3;
    Solution c;
    cout<<c.countNumbersWithUniqueDigits(a)<<endl;
    return 0;
}