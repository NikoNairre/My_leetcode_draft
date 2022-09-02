#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<10 and x>=0){return true;}
        if(x<0){return false;}
        string pro_str=to_string(x);
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
    int largestPalindrome(int n) {
        if(n==1){return 9;}
        long inf=(long)pow(10,n-1);
        long sup=inf*10;
        long x=sup-1;long y=sup-1;
        bool flag=false;
        long long max_palindrome=0;
        for(x=sup-1;x>=9*inf;x--){
            for(y=sup-1;y>=9*inf;y--){
                if(isPalindrome(x*y)){
                    if(max_palindrome<x*y){
                        max_palindrome=x*y;
                    }
                }
            }
        }
        return (int)max_palindrome%1337;
    }
};
int main(){
    
    return 0;
}