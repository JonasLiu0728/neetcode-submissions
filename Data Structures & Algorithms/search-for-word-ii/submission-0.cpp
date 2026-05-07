class Solution {
public:
    
    struct TrieNode {
        TrieNode* children[26]; // trie node指向的26個子節點
        string word = "";
        TrieNode(){
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){ //word裡面的所有char
            int index = c - 'a';//指向哪裡
            if( curr->children[index] == nullptr ){ //發現還沒有這個字
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->word = word;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode;
        for(string w : words) insert(w);

        vector<string> result;

        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root,result);
            }
        }
        delete root;
        return result;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& result){
        if( i<0 || j<0 || i>=board.size() || j>=board[0].size() ) return;

        char c = board[i][j];

        if( c=='*'||curr->children[c-'a']==nullptr ) return;
        curr = curr->children[c-'a'];

        if(!curr->word.empty()){ //這邊不懂
            result.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '*';

        //往四個方向dfs
        dfs(board, i+1, j, curr, result);
        dfs(board, i, j+1, curr, result);
        dfs(board, i-1, j, curr, result);
        dfs(board, i, j-1, curr, result);

        //回復
        board[i][j] = c;
    }
};