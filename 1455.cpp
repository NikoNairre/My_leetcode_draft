#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string>div_words(string sentence){
        vector<string>words;
        int i=0; int word_len=0;
        int start_pos=i;
        while(i<sentence.size()){
            if(sentence[i]!=' '){
                word_len++;
                i++;
                continue;
            }else{
                string word=sentence.substr(start_pos,word_len);
                words.emplace_back(word);
                start_pos=i+1;
                word_len=0;
                i++;
            }
        }
        string final_str=sentence.substr(start_pos,word_len);
        words.emplace_back(final_str);
        return words;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.length();
        vector<string>divided_words=div_words(sentence);
        int find_pos=-1;
        for(int i=0;i<divided_words.size();i++){
            if(divided_words[i].length()<n){
                continue;
            }
            string prefix=divided_words[i].substr(0,n);
            if(prefix.compare(searchWord)==0){
                find_pos=i+1;
                break;
            }
        }
        return find_pos;
    }
};

int main(){
    string a="i love eating burger";
    string s="burg";
    Solution b;
    vector<string>r=b.div_words(a);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<endl;
    }
    cout<<b.isPrefixOfWord(a,s)<<endl;
    return 0;
}