#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>a={1,2,3,4,5};
    a.insert(a.begin()+1,1,8);
    cout<<a[1]<<endl;
    a.erase(a.begin(),a.begin()+1);
    cout<<a[0]<<endl;;
    return 0;
}