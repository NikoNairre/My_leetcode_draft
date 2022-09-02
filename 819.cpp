#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;
vector<string> Separate_words(string sentence){
    vector<string>words;
    string check="!?',;.";
    string tp;
    for(int i=0;i<sentence.length();i++){       
        if(sentence[i]>=65 and sentence[i]<=90){
            tp+=sentence[i]+32;
        }else if(sentence[i]>=97 and sentence[i]<=122){
            tp+=sentence[i];
        }else if(sentence[i]=='!' or sentence[i]=='?' or sentence[i]==',' or sentence[i]==';' or sentence[i]=='.'){
            if(i==sentence.length()-1){
                words.emplace_back(tp);
            }
            continue;
        }else{
            words.emplace_back(tp);
            tp="";
        }          
    }
    return words;
}
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string>words=Separate_words(paragraph);
        unordered_map<string,int>pool;
        for(auto word:words){
            if(count(banned.begin(),banned.end(),word)!=0){
                continue;
            }
            if(pool.find(word)==pool.end()){
                pool[word]=1;
            }else{
                pool[word]++;
            }
        }

    }
};

int main(){
    string s="Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string>v=Separate_words(s);
    map<string,int>ts;
    for(auto item:v){
        if(ts.find(item)==ts.end()){
            ts[item]=1;
        }else{
            ts[item]++;
        }
    }
    for(auto iter=ts.begin();iter!=ts.end();iter++){
        cout<<iter->first<<endl;
    }
    return 0;
}