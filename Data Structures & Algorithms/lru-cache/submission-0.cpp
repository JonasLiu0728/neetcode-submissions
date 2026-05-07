class LRUCache {
private:
    struct node{
        int key;
        int value;
        node* next;
        node* prev;
        node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
    };
    unordered_map<int,node*> table; 
    int capacity;
    int size=0;
    node* head;
    node* tail;
    // dummy nodes
    node* dummy_head = new node(-1,-1);
    node* dummy_tail = new node(-2,-2);
public:
    LRUCache(int cap) {
        capacity = cap;
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }
    
    
    
    void remove_node(node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    void insert_back(node* curr){
        curr->prev = dummy_tail->prev;
        curr->next = dummy_tail;
        dummy_tail->prev->next = curr;
        dummy_tail->prev = curr;
    }

    int get(int key) {
        if (table.find(key) == table.end()) {
            return -1;
        }
        // 直接操作原有的節點
        node* curr = table[key];
        remove_node(curr);
        insert_back(curr);
        
        return curr->value;
    }
    void put(int key, int value) {
        if(table.count(key)){
            //存在
            node* curr = table[key];
            curr->value = value; // 更新數值！
            remove_node(curr);
            insert_back(curr);
        }
        else{//不存在
            //空間夠
            node* newNode = new node(key,value);
            table.insert({key,newNode});
            if(size<capacity){
                insert_back(newNode);
                size++;
            }
            //空間不夠
            else{
                // Put it at the back of list
                node* curr = dummy_head->next;
                table.erase(dummy_head->next->key);
                remove_node(curr);
                delete curr;
                insert_back(newNode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 /**
真正的第一個節點（Head）： 永遠是 dummy_head->next
真正的最後一個節點（Tail）： 永遠是 dummy_tail->prev
判斷串列是否為空： 永遠是檢查 dummy_head->next == dummy_tail
*/