#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_differ=1e6;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]<min_differ){
                min_differ=arr[i+1]-arr[i];
            }
        }
        vector<vector<int>>result;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==min_differ){
                result.push_back({arr[i],arr[i+1]});
            }
        }
        return result;        
    }
};

int main(){

    return 0;
}