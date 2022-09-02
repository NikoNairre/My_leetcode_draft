#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp=vector<vector<int>>(n,vector<int>(n,0));
        unordered_map<int,int>value_key;
        for(int i=0;i<n;i++){
            value_key[arr[i]]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=2;
            }
        }

        int max_len=-1;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dif=arr[j]-arr[i];
                if(value_key.count(dif)){
                    int index=value_key[dif];
                    dp[i][j]=max(dp[i][j],dp[index][i]+1);
                }
                max_len=max(dp[i][j],max_len);
            }
        }
        if(max_len<3){
            return 0;
        }else{
            return max_len;
        }
    }
};

int main(){

    return 0;
}