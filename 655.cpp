#include<iostream>
#include<vector>
#include<string>
#include<cmath>
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
    vector<vector<string>> printTree(TreeNode* root) {
        calHeight(root,0);
        int m=height+1;
        int n=pow(2,height+1)-1;
        string_pool=vector<vector<string>>(m,vector<string>(n,""));
        fill_matrix(root,0,(n-1)/2);
        return string_pool;
    }
    void calHeight(TreeNode* cur_node,int cur_height){
        if(cur_node==nullptr){
            return;
        }
        height=max(height,cur_height);
        if(cur_node->left){
            calHeight(cur_node->left,cur_height+1);
        }
        if(cur_node->right){
            calHeight(cur_node->right,cur_height+1);
        }
    }
    void fill_matrix(TreeNode* cur,int row,int col){
        if(cur==nullptr){
            return;
        }
        string_pool[row][col]=to_string(cur->val);
        if(cur->left){
            fill_matrix(cur->left,row+1,col-pow(2,height-row-1));
        }
        if(cur->right){
            fill_matrix(cur->right,row+1,col+pow(2,height-row-1));
        }
    }
    void showHeight(int h){cout<<height<<endl;}
private:
    int height=-1;
    vector<vector<string>>string_pool;
};

int main(){
    TreeNode* test=new TreeNode(1);
    test->left=new TreeNode(2);
    Solution a;
    vector<vector<string>>sss=a.printTree(test);
    for(int i=0;i<sss.size();i++){
        for(int j=0;j<sss[0].size();j++){
            cout<<sss[i][j]<<" ";
        }
    }
    return 0;
}