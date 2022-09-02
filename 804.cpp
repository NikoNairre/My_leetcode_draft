#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse_code={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>pos_res;
        for(auto word:words){
            string mos="";
            for(int i=0;i<word.size();i++){
                mos+=morse_code[word[i]-97];
            }
            if(pos_res.count(mos)==0){
                pos_res.emplace(mos);
            }
        }
        return pos_res.size();
    }
};
int main(){
    vector<string>b={"gin","zen","gig","msg"};
    Solution a;
    cout<<a.uniqueMorseRepresentations(b)<<endl;
    return 0;
}