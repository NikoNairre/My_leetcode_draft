#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& arr,int k){
        int len=arr.size();
        if(k<1 or k>len){
            return;
        }
        int mid=k/2;
        for(int i=0;i<mid;i++){
            int aim=arr[k-1-i];
            arr[k-1-i]=arr[i];
            arr[i]=aim;
        }
    }
    pair<int,int> max_val_pos(vector<int>&arr){
        int max_num=INT_MIN;
        int max_pos=0;
        for(int i=0;i<arr.size();i++){
            if(max_num<arr[i]){
                max_num=arr[i];
                max_pos=i;
            }
        }
        pair<int,int>val_pos=make_pair(max_num,max_pos);
        return val_pos;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>answer;
        while(arr.size()>1){
            pair<int,int> maxv_maxp=max_val_pos(arr);
            int big=maxv_maxp.first; int pos=maxv_maxp.second;
            if(big!=arr[arr.size()-1]){
                reverse(arr,pos+1);
                answer.emplace_back(pos+1);
                reverse(arr,arr.size());
                answer.emplace_back(arr.size());
            }
            arr.resize(arr.size()-1);
        }
        return answer;
    }
};

int main(){
    vector<int>b={1,2,3,4,56,7};
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    Solution a;
    pair<int,int>t=a.max_val_pos(b);
    cout<<t.first<<" "<<t.second<<endl;
    return 0;
}