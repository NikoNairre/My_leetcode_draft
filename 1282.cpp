#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>size_values;
        for(int i=0;i<groupSizes.size();i++){
            size_values[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>answers;
        unordered_map<int,vector<int>>::iterator it;
        for(it=size_values.begin();it!=size_values.end();it++){
            int cur_size=it->first;
            vector<int>cur_pos=it->second;
            vector<int>cur; int cur_num=0;
            for(int i=0;i<cur_pos.size();i++){
                cur.push_back(cur_pos[i]);
                cur_num++;
                if(cur_num==cur_size){
                    answers.emplace_back(cur);
                    cur={};
                    cur_num=0;
                }
            }
        }
        return answers;
    }
};

int main(){
    unordered_map<int,int>s;
    s[0]=1;
    s[1]=3;
    s[4]=8;
    cout<<s.size();
    unordered_map<int,int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<it->first<<endl;
    }
    return 0;
}