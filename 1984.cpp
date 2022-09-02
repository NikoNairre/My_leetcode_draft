#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1){return 0;}
        sort(nums.begin(),nums.end());
        int min_gap=INT_MAX;
        for(int i=k-1;i<nums.size();i++){
            min_gap=min(min_gap,nums[i]-nums[i-k+1]);
        }
        return min_gap;
    }
};

int main(){
    Solution a;
    int k=2;
    vector<int>b={9,4,1,7};
    cout<<a.minimumDifference(b,k);
    return 0;
}