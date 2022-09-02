#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>brackets;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brackets.emplace(s[i]);
                if(brackets.size()>1){
                    res+=s[i];
                }
            }else{
                brackets.pop();
                if(!brackets.empty()){
                    res+=s[i];
                }
            }
        }
        return res;
    }
};
int main(){
    string a="(()())(())(()(()))";
    Solution b;
    cout<<b.removeOuterParentheses(a)<<endl;
    return 0;
}