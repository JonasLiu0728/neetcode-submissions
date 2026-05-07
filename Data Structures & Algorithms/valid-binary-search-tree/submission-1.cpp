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
public:
    void traversal(TreeNode* root,long long min,long long max,bool& status){
        if(root==nullptr || status==false) return;
        if( root->val<=min || root->val>=max ) status=false;
        traversal(root->left,min,root->val,status);
        if(status) traversal(root->right,root->val,max,status);
    }
    bool isValidBST(TreeNode* root) {
        bool result = true;
        traversal(root,LLONG_MIN,LLONG_MAX,result);
        return result;
    }
};