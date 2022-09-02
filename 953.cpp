#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char>letter_list;
        for(int i=0;i<26;i++){
            letter_list[order[i]]=char(97+i);
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j]=letter_list[words[i][j]];
            }
        }
        bool match=true;
        for(int i=0;i<words.size()-1;i++){
            if(words[i]>words[i+1]){
                match=false;
                break;
            }
        }
        return match;
    }
};

int main(){
    string test="hlabcdefgijkmnopqrstuvwxyz";
    vector<string>w={"word","world","row"};
    Solution a;
    cout<<a.isAlienSorted(w,test)<<endl;
    return 0;
}