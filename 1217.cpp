class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_set<int> pos_positions;
        for(int i=0;i<position.size();i++){
            pos_positions.emplace(position[i]);
        }
        int res=1e9;
        unordered_set<int>::iterator iter;
        for(iter=pos_positions.begin();iter!=pos_positions.end();iter++){
            int cur_pos=*iter;
            int cur_res=0;
            for(int i=0;i<position.size();i++){
                cur_res+=abs(position[i]-cur_pos)%2;
            }
            res=min(res,cur_res);
        }
        return res;
    }
};