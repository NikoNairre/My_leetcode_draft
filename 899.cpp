#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }else{
            int n=s.size();
            string res=s;
            for(int i=0;i<n-1;i++){
                string cur=s.substr(i+1,n-i-1)+s.substr(0,i)+s[i];
                if(cur<res){
                    res=cur;
                }
            }
            return res;
        }
    }
};

int main(){
    string test="bacadeeswdfa";
    Solution a;
    cout<<a.orderlyQueue(test,1)<<endl;
    return 0;
}