#include<iostream>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string res;
        if(n%2!=0){
            res=string(n,'a');
        }else{
            res="b"+string(n-1,'a');
        }
        return res;
    }
};

int main(){
    int r=6;
    Solution a;
    cout<<a.generateTheString(r);
    return 0;
}