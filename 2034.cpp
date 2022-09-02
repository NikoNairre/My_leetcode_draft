#include<iostream>
#include<map>
using namespace std;

int main(){
    map <int,int> temp;
    temp.emplace(make_pair(7,3));
    temp[2]=4;
    cout<<temp.size()<<endl;
    pair<int,int> a=*temp.find(7);
    cout<<a.first<<" "<<a.second<<endl;
    cout<<temp.begin()->first<<" "<<temp.begin()->second<<endl;
    cout<<" "<<temp.rbegin()->first<<" "<<temp.rbegin()->second<<endl;
    return 0;
}