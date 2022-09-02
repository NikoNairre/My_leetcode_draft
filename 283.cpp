#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count0=0;
        vector<int>zero_pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
                zero_pos.push_back(i);
            }
        }
        for(int pos:zero_pos){
            nums.erase(nums.begin()+pos,nums.begin()+pos+1);
        }
    }
};

int main(){
    vector<int>t={0,1,0,3,12,0};
    t.erase(t.begin()+5,t.begin()+6);
   // t.emplace_back(0);
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
    return 0;
}