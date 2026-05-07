class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<ListNode*> nodes;
        ListNode* current = head;
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }

        int i = 0;
        int j = nodes.size() - 1;
        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;
            
            if (i == j) break;

            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};