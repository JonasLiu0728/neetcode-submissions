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
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true; 
        //算自己是否平衡
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if( abs(left_depth-right_depth) > 1 ) return false;
        //判斷左邊右邊是不是平衡
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};