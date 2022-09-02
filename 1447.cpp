#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int gcd(int x,int y){
        int temp;
        if(x<y){
            temp=x;
            x=y;
            y=temp;
        }
        while(y>0){
            temp=x%y;
            x=y;
            y=temp;

        }
        return x;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> answers;
        if(n==1){
            return answers;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(gcd(i,j)==1){
                    answers.emplace_back(to_string(j)+'/'+to_string(i));
                }
            }
        }
        return answers;
    }
};

int main(){

    return 0;
}