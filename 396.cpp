#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum_array=accumulate(nums.begin(),nums.end(),0);
        int max_res=INT_MIN;
        vector<int>rotate_value=vector<int>(n,0);
        for(int i=0;i<n;i++){
            rotate_value[0]+=i*nums[i];
            max_res=max(max_res,rotate_value[0]);
        }
        for(int k=1;k<n;k++){
            rotate_value[k]=rotate_value[k-1]+sum_array-n*nums[n-k];
            max_res=max(max_res,rotate_value[k]);
        }
        return max_res;
    }
};

int main(){
    vector<int>n={1,2,3,4,5};
    n.emplace(n.begin(),n.back());
    n.erase(n.end()-1,n.end());
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
    return 0;
}