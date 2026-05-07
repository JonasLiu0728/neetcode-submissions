/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int traversal(TreeNode* root,int max){
        if(root==nullptr) return 0;
        if( root->val >= max ){
            max = root->val;
            return traversal(root->left,max)+traversal(root->right,max)+1;
        }
        else{
            return traversal(root->left,max)+traversal(root->right,max);
        }      
    }
public:
    int goodNodes(TreeNode* root) {
        int result=traversal(root,root->val);
        return result;
    }
};