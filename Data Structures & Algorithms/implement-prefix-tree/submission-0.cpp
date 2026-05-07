class PrefixTree {
private:
    // 1. 定義內部節點結構
    struct TrieNode {
        TrieNode* children[26]; // 指向 26 個可能子節點的指標陣列
        bool is_end;            // 標記是否為單字的結尾

        TrieNode() {
            is_end = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    // 2. 宣告根節點指標
    TrieNode* root;

public:
    // 初始化 PrefixTree 物件
    PrefixTree() {
        root = new TrieNode();
    }
    
    // 插入單字
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; // 計算字元對應的索引值 (0-25)
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->is_end = true; // 標記單字結尾
    }
    
    // 搜尋單字（必須完全符合且為單字結尾）
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false; // 找不到對應的節點，提早回傳 false
            }
            curr = curr->children[index];
        }
        return curr->is_end; // 確認最後停下的節點是否為合法單字的結尾
    }
    
    // 搜尋前綴（只需確認路徑存在即可）
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true; // 只要能走完前綴字元的路徑，即代表存在該前綴
    }
};