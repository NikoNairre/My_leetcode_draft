#include<iostream>
#include<vector>
#include<limits>
using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*>q;
        q.emplace_back(root);
        int ans=1;
        int max_sum=INT_MIN;
        for(int level=1;!q.empty();level++){
            int cur_sum=0;
            vector<TreeNode*>next_level;
            for(auto node:q){
                if(node->left){
                    next_level.emplace_back(node->left);
                }
                if(node->right){
                    next_level.emplace_back(node->right);
                }
                cur_sum+=node->val;
            }
            if(cur_sum>max_sum){
                max_sum=cur_sum;
                ans=level;
            }
            q=move(next_level);
        }
        return ans;
    }
};


int main(){
    vector<int>a1={1,2,3,4,5};
    vector<int>a2={2,3,3,4};
    a1=move(a2);
    for(int i=0;i<a1.size();i++){
        cout<<a1[i]<<" ";
    }
    return 0;
}