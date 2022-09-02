#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<pair<int,char>>not_letters;
        string letters="";
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>=65 and s[i]<=90) or (s[i]>=97 and s[i]<=122)){
                letters+=s[i];
            }else{
                not_letters.emplace_back(make_pair(i,s[i]));
            }
        }
        for(int i=not_letters.size()-1;i>=0;i--){
            letters.insert(not_letters[i].first,1,not_letters[i].second);
        }
        return letters;
    }
};

int main(){
    Solution a;
    cout<<a.reverseOnlyLetters("da-cb");
    return 0;
}