#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    static bool stringcheck(const string& a,const string& b){
        if(a.size()!=b.size()){
            return a.size()<b.size();
        }else{
            return a>b;
        }
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),stringcheck);
        set<string>accepted_words;
        accepted_words.emplace("");
        string result="";
        for(auto item:words){
            if(accepted_words.count(item.substr(0,item.size()-1))>0){
                accepted_words.emplace(item);
                result=item;
            }
        }
        return result;
    }
};
int main(){

    return 0;
}