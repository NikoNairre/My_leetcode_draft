#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int max_score=0;
        int str_len=s.size();
        for(int i=1;i<str_len;i++){
            string left_part=s.substr(0,i);
            string right_part=s.substr(i,str_len-i);
            int cur_score=count(left_part.begin(),left_part.end(),'0')+count(right_part.begin(),right_part.end(),'1');
            max_score=max(cur_score,max_score);
        } 
        return max_score;   
    }
};

int main(){

    return 0;
}