#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numsAppearSubstr(string sub,string ori){
        int nums=0;
        int index=0;
        while((index=ori.find(sub,index))<ori.size()){
            nums++;
            index++;
        }
        return nums;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>answer;
        string check_pool;
        for(auto word:words){
            check_pool+=word+',';
        }
        for(auto sigword:words){
            if(numsAppearSubstr(sigword,check_pool)>=2){
                answer.emplace_back(sigword);
            }
        }
        return answer;
    }
};

int main(){
    string c="abfjieabngakjrngab";
    int nums=0;
    int index=0;
    while((index=c.find("ab",index))<c.length()){
        nums++;
        index++;
    }
    cout<<nums<<endl;
    return 0;
}