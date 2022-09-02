#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arr_len=arr.size();
        vector<int>support_arr=arr;
        sort(support_arr.begin(),support_arr.end());
        map<int,int>pos_val;
        for(int i=0;i<arr_len;i++){
            pos_val[i]=support_arr[i];
        }
        int chunks=0,max_num=-1;
        for(int i=0;i<arr_len;i++){
            max_num=max(max_num,arr[i]);
            if(max_num==pos_val[i]){
                chunks++;
            }
        }
        return chunks;
    }
};

int main(){
    Solution a;
    vector<int>b={2,1,3,4,4};
    cout<<a.maxChunksToSorted(b);
    return 0;
}