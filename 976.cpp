#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool compare(int a,int b){
        return a>b;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};

int main(){
    vector<int>t={1,2,5,6,34,7,3};
    return 0;
}