#include<iostream>
#include<vector>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return bulid_tree(nums,0,nums.size()-1);
    }
    TreeNode* bulid_tree(vector<int>& nums,int left,int right){
        if(left<right){
            return nullptr;
        }

    }
};

int main(){

    return 0;
}