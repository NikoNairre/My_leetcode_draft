#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string> n_lines=vector<string>(numRows,"");
        int base=numRows*2-2;
        int mid_base=base/2;
        for(int i=0;i<s.size();i++){
            int position=i%base;
            if(position>mid_base){
                position=base-position;
            }
            n_lines[position]+=s[i];
        }
        string answer="";
        for(auto item: n_lines){
            answer+=item;
        }
        return answer;
    }
};

int main(){
    string a="PAYPALISHIRING";
    Solution c;
    cout<<c.convert(a,3)<<endl;
    return 0;
}