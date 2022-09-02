#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_customer=0;
        for(auto customer:accounts){
            int acc=accumulate(customer.begin(),customer.end(),0);
            max_customer=max(max_customer,acc);
        }
        return max_customer;
    }
};
int main(){
    vector<int>s={1,2,3,4,5,6,7,8,9,10};
    int t=accumulate(s.begin(),s.end(),0);
    cout<<t<<endl;
    return 0;
}