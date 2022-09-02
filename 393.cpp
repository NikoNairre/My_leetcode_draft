#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool result=true;
        int i=0;
        int limit_size=data.size();
        while(i<limit_size){
            if(data[i]>=248 or(data[i]>=128 and data[i]<192)){
                result=false;
                break;
            }
            if((data[i]>>7)==0){
                if(i+1>=limit_size){
                    result=true;
                }
                i++;
            }else{
                int check=data[i]>>4;
                if(check==0b1100 or check==0b1101){
                    if(i+1>=limit_size){
                        result=false;
                        break;
                    }
                    if(data[i+1]>>6!=0b10){
                        result=false;
                        break;
                    }
                    i+=2;
                }else if(check==0b1110){
                    if(i+2>=limit_size){
                        result=false;
                        break;
                    }
                    for(int j=1;j<=2;j++){
                        if(data[i+j]>>6!=0b10){
                            result=false;
                            break;
                        }
                    }
                    if(result==false){break;}
                    i+=3;
                }else if(data[i]>>3==0b11110){
                    if(i+3>=limit_size){
                        result=false;
                        break;
                    }
                    for(int j=1;j<=3;j++){
                        if(data[i+j]>>6!=0b10){
                            result=false;
                            break;
                        }
                    }
                    if(result==false){break;}
                    i+=4;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution a;
    vector<int>b={240,162,138,147};
    cout<<a.validUtf8(b)<<endl;
    return 0;
}