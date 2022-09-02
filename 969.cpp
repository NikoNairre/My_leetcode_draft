#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
class Solution {
public:
    bool is_order(vector<int>& arr){
        bool order=true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                order=false;
                break;
            }
        }
        return order;
    }
    void reverse(vector<int>& arr,int k){
        int len=arr.size();
        if(k<1 or k>len){
            return;
        }
        int mid=k/2;
        for(int i=0;i<mid;i++){
            int aim=arr[k-1-i];
            arr[k-1-i]=arr[i];
            arr[i]=aim;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>answer;
        int k=0; int m=arr.size();
        while(!is_order(arr) and answer.size()<m*10-1){
            k=rand()%m+1;
            reverse(arr,k);
            answer.push_back(k);
            if(is_order(arr)){break;}
        }
        return answer;
    }
};

int main(){
    unsigned seed=time(0);
    srand(seed);
    vector<int> test={1,2,3,4,6,5,78,22};
    Solution a;
    vector<int> result=a.pancakeSort(test);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}