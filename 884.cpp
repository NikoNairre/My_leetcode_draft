#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> blank_position(string test){
    vector<int>blanks;
    blanks.push_back(0);
    for(int i=0;i<test.size();i++){
        if(test[i]==' '){
            blanks.push_back(i);
        }
    }
    return blanks;
}

vector<string> separate_word(string test){
    vector<int>blanks=blank_position(test);
    vector<string> words;
    words.push_back(test.substr(0,blanks[1]));
    for(int i=1;i<blanks.size();i++){
        words.push_back(test.substr(blanks[i]+1,blanks[i+1]-blanks[i]-1));
    }
    return words;
}



int main(){
    string s1="this apple is sweet";
    string s2="this apple is sour";
    string s=s1+" "+s2;
    vector<string> words=separate_word(s);

    
    return 0;
}