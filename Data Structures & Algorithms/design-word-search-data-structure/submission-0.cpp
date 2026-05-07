class WordDictionary {
    struct TrieNode{
        TrieNode* children[26];
        bool is_end;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
            is_end = false;
        }
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int index = c - 'a';
            if( curr->children[index]==nullptr ){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return recursive_search(word,curr,0);
    }
    bool recursive_search(string& word,TrieNode* curr,int index){
        if( index == word.size() ) return curr->is_end;
        if(word[index] == '.'){
            for(int i=0;i<26;i++){
                if (curr->children[i] != nullptr) {
                    // 短路求值：只要有一條路徑走通，就立刻宣告成功
                    if (recursive_search(word, curr->children[i], index + 1)) {
                        return true; 
                    }
                }
            }
            return false;
        }
        else{
            int temp = word[index] - 'a';
            if( curr->children[temp]==nullptr ) return false; //找不到
            else return recursive_search( word,curr->children[temp],index+1 ); // 繼續往下找
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */