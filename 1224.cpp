#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int>num_appears;
        int max_freq=0;
        int specie_hasmaxf=0;
        int species=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(num_appears.find(cur)==num_appears.end()){
                num_appears[cur]=1;
                species++;
            }else{
                num_appears[cur]++;
            }                        
            if(num_appears[cur]==max_freq){
                specie_hasmaxf++;
            }else if(num_appears[cur]>max_freq){
                specie_hasmaxf=1;
            }
            max_freq=max(max_freq,num_appears[cur]);
            if(max_freq==1 or (max_freq*specie_hasmaxf==i) or (specie_hasmaxf==1 and max_freq==i/species+1)){
                res=i+1;
            }
        }
        return res;
    }
};

int main(){
    vector<int>n={2,2,1,1,5,3,3,5};
    Solution a;
    cout<<a.maxEqualFreq(n)<<endl;
    return 0;
}