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
    void traversal(TreeNode* root, int level, vector<vector<int>>& result){
        if(root == nullptr) return;
        if(result.size()<=level){ //size應該比level大1
            result.push_back({});
        }
        result[level].push_back(root->val);
        traversal(root->left,level+1,result);
        traversal(root->right,level+1,result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traversal(root,0,result);
        return result;
    }
};