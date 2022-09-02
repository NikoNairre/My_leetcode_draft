#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int first_pos;int last_pos;
        vector<int>pos;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                pos.push_back(i);
            }
        }
        first_pos=pos[0];
        last_pos=pos[pos.size()-1];
        vector<int>res(s.size(),0);
        for(int i=first_pos;i<=last_pos;i++){
            if(count(pos.begin(),pos.end(),i)!=0){
                res[i]=0;
            }else{
                res[i]=res[i-1]+1;
            }
        }
        for(int i=last_pos;i>=first_pos;i--){
            if(count(pos.begin(),pos.end(),i)!=0){
                res[i]=0;
            }else{
                res[i]=min(res[i],res[i+1]+1);
            }
        }
        for(int i=first_pos-1;i>=0;i--){
            res[i]=res[i+1]+1;
        }
        for(int i=last_pos+1;i<res.size();i++){
            res[i]=res[i-1]+1;
        }
        return res;
    }
};

int main(){
    string s="loveleetcode";
    char c='e';
    Solution b;
    vector<int>t=b.shortestToChar(s,c);
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
    return 0;
}