#include<iostream>
using namespace std;

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
    int sum=0,depth=0,max_depth=0;
    int deepestLeavesSum(TreeNode* root) {
        
        dfs(root,0);
        return sum;
    }
    void dfs(TreeNode* cur_node,int depth){
        if((cur_node->left==nullptr) and (cur_node->right==nullptr)){
            if(depth>max_depth){
                sum=cur_node->val;
            }else if(depth==max_depth){
                sum+=cur_node->val;
            }
            max_depth=max(depth,max_depth);
        }
        if(cur_node->left){
            dfs(cur_node->left,depth+1);
            max_depth=max(depth,max_depth);
        }
        if(cur_node->right){
            dfs(cur_node->right,depth+1);
            max_depth=max(depth,max_depth);
        }
    }
};

int main(){

    return 0;
}