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
    int GetLength(ListNode* l1){
        int length = 0;
        while(l1 -> next != nullptr){
            length++;
            l1 = l1->next;
        } 
        length++;
        return length;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int max_length,min_length;//較小的那個length
        //讓l1都是比較長的那個, min_length是l2
        if(GetLength(l2)>=GetLength(l1)){
            ListNode* temp;
            temp = l1;
            l1 = l2;
            l2 = temp;
        } 
        max_length = GetLength(l1);
        min_length = GetLength(l2);

        ListNode* current_l1 = l1;
        ListNode* current_l2 = l2;
        //開始相加
        //重複的部分
        bool carry = 0;
        for(int i=0;i<min_length;i++){
            current_l1->val += current_l2->val;
            if(carry) current_l1->val+=1;
            if(current_l1->val >= 10){
                current_l1->val = current_l1->val % 10;
                carry = 1;
            }
            else carry = 0;
            //移動pointer
            current_l1 = current_l1->next;
            current_l2 = current_l2->next;
        }

        //單獨的部分
        for(int i=min_length;i<max_length;i++){
            if(carry) current_l1->val+=1;
            if(current_l1->val >= 10){
                current_l1->val = current_l1->val % 10;
                carry = 1;
            }
            else carry = 0;
            current_l1 = current_l1->next;
        }


        current_l1 = l1;
        if(carry){
            ListNode* last = new ListNode(1);
            while(current_l1->next != nullptr){
                current_l1 = current_l1->next;
            }
            //進位
            current_l1->next = last;
        }

        return l1;
    }
};