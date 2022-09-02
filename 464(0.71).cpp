#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        if (((maxChoosableInteger) * (1 + maxChoosableInteger) / 2) < desiredTotal) {
            return false;
        }
        set<int>num_pool;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            num_pool.emplace(i);
        }
        int pick_round = 0;
        while (desiredTotal > 0) {
            if (num_pool.size() == 0) {
                break;
            }
            if (desiredTotal > *num_pool.rbegin()) {
                int pick_num = *num_pool.begin();
                desiredTotal -= pick_num;
                pick_round++;
                num_pool.erase(pick_num);
            }
            else {
                int pick_num = *num_pool.rbegin();
                desiredTotal -= pick_num;
                pick_round++;
                num_pool.erase(pick_num);
            }
        }
        bool win = false;
        if (pick_round % 2 == 0) {
            win = false;
        }
        else {
            win = true;
        }
        return win;
    }
};
int main(){
    Solution a;
    int n1=10;
    int n2=18;
    cout<<a.canIWin(n1,n2)<<endl;
    return 0;
}