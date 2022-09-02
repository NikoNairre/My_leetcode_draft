#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int remain=n;
    bool flag=true;
    int step=1;
    int remain_key=1;
    while(remain>1){

        if(flag==true or remain>>1==1){
            remain_key+=step;
        }
        step*=2;
        flag=not flag;
        remain>>=1;
    }
    cout<<remain_key<<endl;;
    return 0;
}