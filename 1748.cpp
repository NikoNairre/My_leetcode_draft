/*给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
请你返回 nums 中唯一元素的 和 。*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>all_nums;
        for(auto i:nums){
            all_nums[i]=0;
        }
        for(auto i:nums){
            all_nums[i]++;
        }
        int answer=0;
        for(auto item:all_nums){
            if(item.second==1){
                answer+=item.first;
            }
        }
        return answer;
    }
};

int main(){
    Solution a;
    vector<int>b={1,2,3,2};
    vector<int>c={1,1,1,1,1};
    vector<int>d={1,2,3,4,5};
    cout<<a.sumOfUnique(b)<<endl;
    cout<<a.sumOfUnique(c)<<endl;
    cout<<a.sumOfUnique(d)<<endl;
    return 0;
}