#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
    int a[5]={1,2,3,4,5};
    int b =accumulate(a,a+3,0);
    cout<<b<<endl;

    return 0;
}