#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>results;
        int n=security.size();
        if(n<2*time+1){
            return results;
        }
        vector<int>lefts=vector<int>(n,0);
        vector<int>rights=vector<int>(n,0);
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                lefts[i]=lefts[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                rights[i]=rights[i+1]+1;
            }
        }
        for(int i=time;i<n-time;i++){
            if(lefts[i]>=time and rights[i]>=time){
                results.emplace_back(i);
            }
        }
        return results;
    }
};

int main(){
    vector<int>a={1,2,3,4,5,6,6};
    vector<int>b=vector<int>(5,2);
    cout<<b.size()<<endl;
    return 0;
}