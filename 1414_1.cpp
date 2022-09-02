#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fib_nums;
        fib_nums.push_back(1);
        int a=1,b=1;
        while(a+b<=k){
            int c=a+b;
            fib_nums.push_back(c);
            a=b;
            b=c;
        }
        int count=0;
        for(int i=fib_nums.size()-1;i>=0;i--){
            if(k>=fib_nums[i]){
                k-=fib_nums[i];
                count++;
            }
            if(k<=0){
                break;
            }
        }
        return count;
    }
};

int main(){
    Solution a;
    cout<<a.findMinFibonacciNumbers(76);
    return 0;
}