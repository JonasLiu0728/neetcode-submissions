/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* current = head;
        for(int i=0;i<n;i++){
            current = current->next;
        }
        //cout<<current->val<<endl;
        ListNode* to_remove = head; //指向要被跳過的節點的前一個
        if(current == nullptr){ //剛好刪除第一個
            return head->next;
        }
        while(current->next!=nullptr ){
            current = current->next;
            to_remove = to_remove->next;
        }
        //刪除node
        to_remove->next = to_remove->next->next;

        return head;
    }
};