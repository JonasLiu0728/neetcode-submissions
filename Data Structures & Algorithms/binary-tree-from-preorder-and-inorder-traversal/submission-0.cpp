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
    int find_index(vector<int>& arr,int target,int in_left,int in_right){
        for(int i=in_left;i<=in_right;i++){
            if(arr[i]==target) return i;
        }
        return -1;
    }
    TreeNode* traversal(int pre_left,int pre_right,int in_left,int in_right,vector<int>& PREORDER,vector<int>& INORDER){
        if(pre_left > pre_right) return nullptr;
        TreeNode* root = new TreeNode(PREORDER[pre_left]);
        //找 preorder 第一個元素在 inorder的位置
        int sep = find_index(INORDER,PREORDER[pre_left],in_left,in_right);//分開兩邊的index
        // pre 左半 = pre_left+1 ~ pre_left+(sep-in_left)
        // pre 右半 = pre_left+(sep-in_left)+1 ~ pre_right
        // in 左半 = in_left~sep-1
        // in 右半 = sep+1 ~ in_right
        root->left = traversal(pre_left+1,pre_left+(sep-in_left),in_left,sep-1 ,PREORDER,INORDER);
        root->right = traversal(pre_left+(sep-in_left)+1,pre_right,sep+1,in_right ,PREORDER,INORDER);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal( 0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};