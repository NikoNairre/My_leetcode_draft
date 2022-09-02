#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start.compare(end) == 0) {
            return 0;
        }
        if (find(bank.begin(), bank.end(), end) == bank.end()) {
            return -1;
        }
        queue<string>pool;
        unordered_set<string>visited;
        char valid_letter[4] = { 'A','C','G','T' };
        pool.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!pool.empty()) {
            int round = pool.size();
            for (int r = 0; r < round; r++) {
                string cur_modify = pool.front();
                pool.pop();
                for (int i = 0; i < 8; i++) {
                    char t = cur_modify[i];
                    for (int j = 0; j < 4; j++) {
                        if (cur_modify[i] == valid_letter[j]) {
                            continue;
                        }
                        cur_modify[i] = valid_letter[j];
                        if ((visited.count(cur_modify) != 0) or (find(bank.begin(), bank.end(), cur_modify) == bank.end())) {
                            continue;
                        }
                        if (cur_modify == end) {
                            return step;
                        }
                        visited.emplace(cur_modify);
                        pool.emplace(cur_modify);                       
                    }
                    cur_modify[i] = t;   //这一轮搜索结束了，要把改动的位置再还原成原本的
                }
            }
            step++;
        }
        return -1;
    }
};
int main(){
    string s="AACCGGTT"; string e="AACCGGTA";
    vector<string>ba={"AACCGGTA"};
    Solution a;
    cout<<a.minMutation(s,e,ba)<<endl;
    return 0;
}