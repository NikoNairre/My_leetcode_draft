#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int arr_len=arr.size();
        int max_arr_num=arr[arr_len-1];
        int longest_len=-1;
        for(int i=0;i<arr_len-2;i++){
            for(int j=i+1;j<arr_len-1;j++){
                int cur_len=2;
                int prev_value=arr[j];
                int cur_value=arr[i]+arr[j];
                while(cur_value<=max_arr_num){
                    const int f_val=cur_value;
                    if(find(arr.begin(),arr.end(),f_val)==arr.end()){
                        break;
                    }else{
                        int temp=prev_value+cur_value;
                        prev_value=cur_value;
                        cur_value=temp;
                        cur_len++;
                    }
                }
                longest_len=max(longest_len,cur_len);
            }
        }
        if(longest_len<3){
            return 0;
        }else{
            return longest_len;
        }
    }
};

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    Solution s;
    cout<<s.lenLongestFibSubseq(arr)<<endl;
    return 0;
}