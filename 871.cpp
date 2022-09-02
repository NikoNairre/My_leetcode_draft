#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int fuel_times=0;
        int cur_position=startFuel;
        priority_queue<int>fuel_queue;
        
    }
};

int main(){
    priority_queue<int>h;
    h.emplace(6);
    h.emplace(2);
    h.emplace(9);
    h.emplace(9);
    h.emplace(3);
    h.emplace(7);
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
    return 0;
}