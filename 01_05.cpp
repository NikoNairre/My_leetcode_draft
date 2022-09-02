#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.compare(second)==0){
            return true;
        }
        if(first.size()<second.size()){
            string temp=second;
            second=first;
            first=temp;
        }
        if(first.size()-second.size()>=2){
            return false;
        }
        bool legal=true;
        if(first.size()==second.size()){
            int differences=0;
            for(int i=0;i<first.size();i++){
                if(first[i]!=second[i]){
                    differences++;
                }
                if(differences>=2){
                    legal=false;
                    break;
                }
            }
        }else{
            int n=second.size();
            int j_first=0; int j_second=0;
            int num_dif=0;
            while(j_second<n){
                if(first[j_first]!=second[j_second]){
                    num_dif++;
                    j_first++;
                }else{
                    j_first++;
                    j_second++;
                }
                if(num_dif>=2){
                    legal=false;
                    break;
                }
                
            }
        }
        return legal;
    }
};



int main(){

    return 0;
}