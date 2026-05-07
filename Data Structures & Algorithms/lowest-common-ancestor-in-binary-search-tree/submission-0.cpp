/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root==nullptr || root==p || root==q ){
            return root;
        }
        TreeNode* LeftResult = lowestCommonAncestor(root->left,p,q);
        TreeNode* RightResult = lowestCommonAncestor(root->right,p,q);

        if( LeftResult!=nullptr && RightResult!=nullptr) return root;
        
        if(LeftResult!=nullptr) return LeftResult;
        else if(RightResult!=nullptr) return RightResult;
        return nullptr;
    }
};