#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    set<char>vowels={'A','E','I','O','U','a','e','i','o','u'};
    vector<string> splitWords(string sentence){
        vector<string>splits;
        string word;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                word+=sentence[i];
                if(i==sentence.size()-1){
                    splits.emplace_back(word);
                }
            }else{
                splits.emplace_back(word);
                word="";
            }
        }
        return splits;
    }
    string toGoatLatin(string sentence) {
        vector<string>words=splitWords(sentence);
        string answer="";
        int num_a=1;
        for(auto word:words){
            if(vowels.find(word[0])!=vowels.end()){
                word+="ma";
                word.insert(word.size(),num_a,'a');
            }else{
                char l=word[0];
                word.erase(0,1);
                word.append(1,l);
                word+="ma";
                word.insert(word.size(),num_a,'a');
            }
            answer+=word+" ";
            num_a++;
        }
        answer.erase(answer.size()-1,1);
        return answer;
    }
};

int main(){
    string t="I speak Goat Latin";
    Solution a;
    cout<<a.toGoatLatin(t)<<endl;
    return 0;
}