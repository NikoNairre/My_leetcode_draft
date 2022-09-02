#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1){return 9;}
        int max_pal=0;
        long upper=pow(10,n)-1;
        for(long left=upper;;left--){
            string lp=to_string(left);
            string rp=lp;
            reverse(rp.begin(),rp.end());
            lp=lp+rp;
            long pal_num=stol(lp);
            
            for(long test=(long)pow(10,n)-1;test*test>=pal_num;test--){
                if(pal_num%test==0){
                    return pal_num%1337;                   
                }
            }         
        }      
    }
};
int main(){
    int n=4;
    Solution a;
    cout<<a.largestPalindrome(n)<<endl;
    return 0;
}