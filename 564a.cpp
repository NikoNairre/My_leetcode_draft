#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1){
            return to_string(stoll(n)-1);
        }
        if(stoll(n)==(long long)pow(10,n.size()-1)+1){
            return to_string(stoll(n)-2);
        }
        if(stoll(n)==(long long)pow(10,n.size()-1)){
            return to_string(stoll(n)-1);
        }
        if(stoll(n)==(long long)pow(10,n.size())-1){
            return to_string(stoll(n)+2);
        }
        int mid=n.size()/2;
        if(n.size()%2==0){
            string base=n.substr(0,mid);
            string r1=base;
            for(int i=base.size()-1;i>=0;i--){
                r1+=base[i];
            }
            string base2=to_string(stoll(base)+1);
            string r2=base2;
            for(int i=base2.size()-1;i>=0;i--){
                r2+=base2[i];
            }
            string base3=to_string(stoll(base)-1); 
            string r3=base3;
            for(int i=base3.size()-1;i>=0;i--){
                r3+=base3[i];
            }
            long long gap1=abs(stoll(n)-stoll(r1));
            long long gap2=abs(stoll(n)-stoll(r2));
            long long gap3=abs(stoll(n)-stoll(r3));
            string result="";
            vector<long long>gaps;
            if(gap1!=0){gaps.push_back(gap1);}
            if(gap2!=0){gaps.push_back(gap2);}
            if(gap3!=0){gaps.push_back(gap3);}
            long long min_gap=LLONG_MAX;
            for(int i=0;i<gaps.size();i++){
                if(min_gap>gaps[i]){
                    min_gap=gaps[i];
                }
            }
            if(min_gap==gap3){
                result=r3;
            }else{
                if(min_gap==gap1){
                    result=r1;
                }else{
                    result=r2;
                }
            }
            return result;                       
        }else{
            string base=n.substr(0,mid+1);
            string r1=base;
            for(int i=base.size()-2;i>=0;i--){
                r1+=base[i];
            }
            string base2=to_string(stoll(base)+1);
            string r2=base2;
            for(int i=base2.size()-2;i>=0;i--){
                r2+=base2[i];
            }
            string base3=to_string(stoll(base)-1); 
            string r3=base3;
            for(int i=base3.size()-2;i>=0;i--){
                r3+=base3[i];
            }
            long long gap1=abs(stoll(n)-stoll(r1));
            long long gap2=abs(stoll(n)-stoll(r2));
            long long gap3=abs(stoll(n)-stoll(r3));
            string result="";
            vector<long long>gaps;
            if(gap1!=0){gaps.push_back(gap1);}
            if(gap2!=0){gaps.push_back(gap2);}
            if(gap3!=0){gaps.push_back(gap3);}
            long long min_gap=LLONG_MAX;
            for(int i=0;i<gaps.size();i++){
                if(min_gap>gaps[i]){
                    min_gap=gaps[i];
                }
            }
            if(min_gap==gap3){
                result=r3;
            }else{
                if(min_gap==gap1){
                    result=r1;
                }else{
                    result=r2;
                }
            }
            return result;  
        }
    }
};

int main(){
    Solution a;
    cout<<a.nearestPalindromic("10001")<<endl;
    string v="123456789";
    cout<<v.substr(0,5)<<endl;
    return 0;
}