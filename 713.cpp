#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int lp=0;int rp=0;
        int mul_num=nums[0];
        while(rp<nums.size()){
            while(mul_num>=k){
                mul_num/=nums[lp];
                lp++;
            }
            count+=rp-lp+1;
            rp++;
        }
        return count;
    }
};

int main(){

    return 0;
}