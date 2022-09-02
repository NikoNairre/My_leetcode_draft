#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.length()==1){
            return dominoes;
        }
        string operation ="L"+dominoes+"R";
        int left_pos=0;
        int right_pos=1;
        for(right_pos=1;right_pos<operation.size();right_pos++){      
            if(operation[right_pos]=='.'){
                continue;
            }
            else if(operation[right_pos]=='L'){
                int num_dots=right_pos-left_pos-1;
                if(operation[left_pos]=='L'){
                    for(int i=left_pos+1;i<right_pos;i++){
                        operation[i]='L';
                    }
                }
                if(operation[left_pos]=='R'){
                    int mid=(left_pos+right_pos)/2;
                    if(num_dots%2==0){
                        for(int i=left_pos+1;i<=mid;i++){
                            operation[i]='R';
                        }
                        for(int i=mid+1;i<right_pos;i++){
                            operation[i]='L';
                        }
                    }else{
                        for(int i=left_pos+1;i<mid;i++){
                            operation[i]='R';
                        }
                        for(int i=mid+1;i<right_pos;i++){
                            operation[i]='L';
                        }                        
                    }
                }
                left_pos=right_pos;
            }else if(operation[right_pos]=='R'){
                if(operation[left_pos]=='R'){
                    for(int i=left_pos+1;i<right_pos;i++){
                        operation[i]='L';
                    }                    
                }
                left_pos=right_pos;
            }
        }
        return operation.substr(1,operation.size()-2);
    }
};
int main(){
    Solution a;
    cout<<a.pushDominoes("RR.L")<<endl;
    cout<<a.pushDominoes(".L.R...LR..L..");
    return 0;
}