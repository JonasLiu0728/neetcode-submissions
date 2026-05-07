//#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    struct node{
        string word;
        vector<node*> neighbors;
        node(string temp){
            word = temp;
        }
        node() {
            word = "";
        }
    };
    bool connect(string& a,string& b){
        int diff = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
            if(diff>1) return false;
        }
        if(diff==1) return true;
        return false;
    }
    int bfs(node* root,string& target){
        queue<pair<node*,int> > Q;
        Q.push({root,1});
        // build a table for visited string(node)
        unordered_set<string> visited;
        visited.insert(root->word);
        //start bfs
        while(!Q.empty()){
            node* top = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(top->word==target) return depth;
            for(node* temp : top->neighbors){
                if (visited.find(temp->word) == visited.end()) {
                    visited.insert(temp->word);  // 標記為已走訪
                    Q.push({temp, depth + 1});   // 推入佇列，距離 +1
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndWordValid = false;
        for (const string& w : wordList) {
            if (w == endWord) isEndWordValid = true;
        }
        if (!isEndWordValid) return 0;

        // [最小改動 2] 重構 G 陣列的初始化：只放入 beginWord
        vector<node> G;
        G.push_back(node(beginWord));
        
        for(int i = 0; i < wordList.size(); i++){
            // [最小改動 3] 避免字典裡本來就有 beginWord 導致節點重複
            if (wordList[i] != beginWord) {
                G.push_back(node(wordList[i])); 
            }
        }
        for(int i = 0; i < G.size(); i++){
            for(int j = i + 1; j < G.size(); j++){
                // 1. 直接使用 G[i] 與 G[j] 內儲存的字串進行比對，確保索引意義一致
                if( connect(G[i].word, G[j].word) ){
                    // 2. 加上 & 符號，將指標存入 neighbors
                    G[i].neighbors.push_back(&G[j]);
                    G[j].neighbors.push_back(&G[i]);
                }
            }
        }
        return bfs(&G[0], endWord);
    }
};