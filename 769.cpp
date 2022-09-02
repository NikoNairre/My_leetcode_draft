#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int max_num=-1;
        for(int i=0;i<arr.size();i++){
            max_num=max(max_num,arr[i]);
            if(max_num==i){
                ans++;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}