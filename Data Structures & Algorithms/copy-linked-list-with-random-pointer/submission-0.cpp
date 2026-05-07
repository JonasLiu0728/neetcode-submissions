/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* dummy = new Node(INT_MIN);
        Node* result = dummy;

        unordered_map<Node*,Node*> node_table; //對應關係
        vector<Node*> random_list; //原本的random列表

        Node* current = head;
        Node* newCurrent = result;
        
        while( current != nullptr){
            // create新的node
            Node* newNode = new Node(current->val);
            node_table[current] = newNode;
            newCurrent->next = newNode;
            //處理random
            random_list.push_back(current->random);
            //建立關係
            
            newCurrent = newCurrent->next;
            current = current->next;
        }
        //output(result->next);
        
        current = result->next;
        for(int i=0;i<random_list.size();i++){
            if(current == nullptr) break;
            current->random = node_table[ random_list[i] ];
            current = current->next;
        }
        return result->next;
    }
};
