#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int gap=1;
        while(gap<=arr.size()){
            int i=0;
            while(arr.begin()+i+gap<=arr.end()){
                ans+=accumulate(arr.begin()+i,arr.begin()+i+gap,0);
                i+=1;
            }
            gap+=2;
        }
        return ans;
    }
};

int main(){
    vector<int>a={1,2,3,4,5,6};
    Solution s;
    cout<<s.sumOddLengthSubarrays(a)<<endl;
    return 0;
}