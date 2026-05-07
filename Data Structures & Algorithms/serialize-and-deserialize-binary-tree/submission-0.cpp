/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string coding_str;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            string to_append;
            if(temp!=nullptr){
                to_append = to_string(temp->val)+"x";
                result.append(to_append);
                q.push(temp->left);
                q.push(temp->right);
            }
            else{
                to_append = "NULLx";
                result.append(to_append);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;
        // Parsing
        for(int i=0;i<data.size();i++){
            string temp = "";
            int start = i;
            while(data[start]!='x'){
                temp+=data[start];
                start++;
            }
            i = start;
            arr.push_back(temp);
        }
        
        // convert into a tree
        
        // Check if the tree is empty
        if( arr.size()==0 || arr[0]=="NULL") return nullptr;
        
        // Reconstruct tree
        TreeNode* root = new TreeNode(stoi(arr[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1; // 0 is the root
        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();
            // add left and right child
            if (index < arr.size() && arr[index] != "NULL"){
                parent->left = new TreeNode(stoi(arr[index]));
                q.push(parent->left);
            }
            index++;
            if (index < arr.size() && arr[index] != "NULL"){
                parent->right = new TreeNode(stoi(arr[index]));
                q.push(parent->right);
            }
            index++;
        }   
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));