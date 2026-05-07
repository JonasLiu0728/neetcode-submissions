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
private:
    int length = INT_MIN;
public:
    int max_length(TreeNode* root){
        if(root==nullptr) return 0;
        int left_gain = max_length(root->left);
        int right_gain = max_length(root->right);
        
        if( left_gain<0 ) left_gain = 0;
        if( right_gain<0 ) right_gain = 0;
        
        length = max( length, root->val+left_gain+right_gain );
        return root->val+max(left_gain,right_gain);
    }
    int maxPathSum(TreeNode* root) {
        max_length(root);
        return length;
    }
};