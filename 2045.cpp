#include<iostream>
#include<vector>
using namespace std;
void print_list(vector<vector<int>> test){
    for(auto item:test){
        for(int i=0;i<item.size();i++){
            cout<<item[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int a[4][2]={{0,0},{0,1},{1,0},{1,1}};
    for(auto e:a){        //e前面加&也可以
        cout<<e[0]<<" "<<e[1]<<endl;
    }
    vector<vector<int>> lists={{2,2},{2,3},{3,2},{3,3,3}};
    for(auto &h:lists){   //h前面去掉&也可以
        cout<<h[0]<<" "<<h[1]<<endl;
    }
    cout<<"Oh,there's nothing,let's look at this:"<<endl;
    vector<int>m=vector<int>(10,4);
    lists.push_back(m);
    print_list(lists);
    vector<vector<int>>hahaha(15);
    print_list(hahaha);
    return 0;
}