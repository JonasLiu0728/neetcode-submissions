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
    void traversal(TreeNode* root, int level, vector<int>& result){
        if(root==nullptr) return;
        // level=2 size=3
        if( result.size()<=level ){
            result.push_back(root->val);
        }
        traversal(root->right,level+1,result);
        traversal(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traversal(root,0,result);
        return result;
    }
};