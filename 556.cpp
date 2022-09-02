#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<limits>
using namespace std;

class Solution {
public:
    vector<int> get_permutation(int num){
        vector<int>res;
        while(num>0){
            res.push_back(num%10);
            num/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int nextGreaterElement(int n) {
        if(n<10){
            return -1;
        }
        vector<int>cur_permutation=get_permutation(n);
        int num_len=cur_permutation.size();
        int cur_pos=num_len-1;
        bool exist_next=false;
        for(int i=num_len-1;i>=1;i--){
            cur_pos=i;
            if(cur_permutation[i]>cur_permutation[i-1]){
                for(int j=num_len-1;j>=i;j--){
                    if(cur_permutation[j]>cur_permutation[i-1]){
                        exist_next=true;
                        swap(cur_permutation[j],cur_permutation[i-1]);
                        sort(cur_permutation.begin()+i,cur_permutation.end());
                        break;
                    }
                }
                break;
            }
        }
        if(!exist_next and cur_pos==1){
            return -1;
        }
        string ans;
        for(int i=0;i<num_len;i++){
            ans+=to_string(cur_permutation[i]);
        }
        if(stoll(ans)>INT_MAX){
            return -1;
        }
        return stoi(ans);

    }
};

int main(){
    int test_num=16;
    Solution a;
    vector<int>r=a.get_permutation(test_num);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<a.nextGreaterElement(test_num);
    return 0;
}