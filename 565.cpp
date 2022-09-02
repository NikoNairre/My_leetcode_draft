#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int>visit(n,0);
        int ans=0;
        for(int k=0;k<n;k++){
            int i=k;
            int cur=0;
            while(visit[i]==0){
                visit[i]=1;
                i=nums[i];
                cur++;
            }
            ans=max(cur,ans);
        }
        return ans;
    }
};

int main(){

    return 0;
}