#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){
    map<char,int>s;
    priority_queue<pair<int,char>>q;
    q.push(make_pair(2,'a'));
    q.push(make_pair(1,'c'));
    q.push(make_pair(4,'b'));
    s['d']=4;
    s['b']=2;
    s['c']=3;
    for(auto &item :s){
        cout<<item.first<<":"<<item.second<<endl;
    }
    cout<<q.top().first<<" "<<q.top().second<<endl;
    pair<char,int>ks=q.top();
    q.pop();
    ks.first-=3;
    q.push(ks);
    cout<<q.top().first<<" "<<q.top().second<<endl;
    return 0;
}