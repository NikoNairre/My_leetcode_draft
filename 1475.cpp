#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res;
        for(int i=0;i<prices.size();i++){
            int discount=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    discount=prices[j];
                    break;
                }
            }
            res.push_back(prices[i]-discount);
        }
        return res;
    }
};

int main(){

    return 0;
}