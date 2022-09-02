#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>words=splitWords(sentence);
        unordered_set<string>pool;
        for(auto dict:dictionary){
            pool.emplace(dict);
        }
        string res;
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                if(pool.count(word.substr(0,i+1))){
                    res+=word.substr(0,i+1);
                    res+=' ';
                    break;
                }
                if(i==word.size()-1){
                    res+=word+' ';
                }

            }
        }
        res.erase(res.size()-1);
        return res;
    }
    vector<string> splitWords(string sentence){
        vector<string>splits;
        int lasting=0;
        for(int i=0;i<sentence.size();i++){
            if(i==sentence.size()-1){
                splits.emplace_back(sentence.substr(i-lasting,lasting+1));
            }
            if(sentence[i]==' '){
                splits.emplace_back(sentence.substr(i-lasting,lasting));
                lasting=0;
            }else{
                lasting++;
            }
        }
        return splits;
    }
};


int main(){
    string s="the cattle was rattled by the battery";
    vector<string>d={"cat","bat","rat"};
    Solution k;
    string r=k.replaceWords(d,s);

    cout<<r<<endl;    
    return 0;
}