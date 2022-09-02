#include<iostream>
using namespace std;
int digits(int x){
    int digit_number=1,digit=1;
    while(x-digit>0){
        digit*=10;
        digit_number++;
    }
    return digit_number-1;
}
int main(){
    int x;
    cin>>x;
    cout<<digits(x)<<endl;
    return 0;
}