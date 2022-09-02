#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
       string answer="";
       int t=num;
       int div_num,rem_num;
       while(num!=0){
           div_num=num/7;
           rem_num=num%7;
           answer.insert(0,to_string(abs(rem_num)));
           num=div_num;
       } 
       if(t<0){
           answer.insert(0,"-");
       }
       return answer;
    }
};

int main(){
    Solution a;
    cout<<a.convertToBase7(-100)<<endl;
    return 0;
}