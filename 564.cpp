#include<iostream>
#include<limits>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long test) {
        if(test<10 and test>=0){return true;}
        if(test<0){return false;}
        string pro_str=to_string(test);
        int len=pro_str.size();
        int mid=len/2;
        bool match=true;
        for(int i=0;i<=mid;i++){
            if(pro_str[i]!=pro_str[len-1-i]){
                match=false;
                break;
            }
        }
        return match;
    }
    string nearestPalindromic(string n) {
        long long num=stoll(n);
        long long bigger=num+1; long long smaller=num-1;
        long long result=0;
        while(true){
            if(isPalindrome(smaller)){
                result=smaller;
                break;
            }else{
                smaller--;
            }
            if(isPalindrome(bigger)){
                result=bigger;
                break;
            }else{
                bigger++;
            }
        }
        return to_string(result);
    }
};

int main(){
    cout<<LLONG_MAX<<endl;
    Solution a;
    cout<<a.nearestPalindromic("123456789")<<endl;
    return 0;
}