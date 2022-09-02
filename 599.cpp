#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> names;
        vector<string> result;
        for(int i=0;i<list1.size();i++){
            names.emplace(make_pair(list1[i],i));
        }
        int min_sum_index=INT_MAX;
        for(int j=0;j<list2.size();j++){
            if(names.count(list2[j])>0){
                int indexs=names[list2[j]]+j;
                if(indexs<min_sum_index){
                    result.clear();
                    min_sum_index=indexs;
                    result.emplace_back(list2[j]);
                }else if(indexs==min_sum_index){
                    result.emplace_back(list2[j]);
                }
            }
        }
        return result;
    }
};

int main(){
    unordered_map<int,int>a;
    a[1]=2;
    a[2]=2;
    a[3]=4;
    a[4]=2;
    //unordered_map<int,int>::iterator it;
    for(auto item:a){
        if(item.second==2){
            cout<<item.first<<":"<<item.second<<endl;
        }
    }
    pair<int,int> t=make_pair(1,2);
    cout<<a.count(a[3])<<endl;
    return 0;
}