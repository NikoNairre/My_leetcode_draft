#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool reverse_sort(int a,int b){
    return a>b;
}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_len=nums.size();
        bool swap_condition=false;
        int cur_pos=nums_len-1;
        for(int i=nums_len-1;i>=1;i--){
            cur_pos=i;
            if(nums[i]>nums[i-1]){
                for(int j=nums_len-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        sort(nums.begin()+i,nums.end());
                        swap_condition=true;
                        break;
                    }
                }
                break;
            }
        }
        if(!swap_condition and cur_pos==1){
            sort(nums.begin(),nums.end());
        }
    }
};

int main(){
    vector<int>array={1,5,2,4,3};
    sort(array.begin(),array.end(),reverse_sort);
    for(int i=0;i<array.size();i++){

        cout<<array[i]<<" ";
    }

    return 0;
}