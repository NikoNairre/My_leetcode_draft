#include<iostream>
#include<vector>
using namespace std;

class Condition{
public:
    int change=0;
};
class Solution {
public:
    bool is_available(int n, Condition test[20]){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(test[i].change!=0){
                flag=false;
                break;
            }
        }
        return flag;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m=requests.size();
        int all_cases=1<<m;
        int result=0;
        for(int i=0;i<all_cases;i++){
            Condition build_changes[20];
            int current_case=i;
            int visit_order=0;
            int choosed_num=0;
            while(current_case>0){
                if(current_case&1){
                    choosed_num++;
                    build_changes[requests[visit_order][0]].change--;
                    build_changes[requests[visit_order][1]].change++;
                }
                current_case=current_case>>1;
                visit_order++;
            }
            if(is_available(n,build_changes)){
                result=max(result,choosed_num);
            }
        }
        return result;        
    }
};

int main(){
    vector<vector<int>>test={{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    Solution a;
    cout<<a.maximumRequests(5,test)<<endl;
    return 0;
}