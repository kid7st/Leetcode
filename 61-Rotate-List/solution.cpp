/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* iter = head;
        int count = 0;
        while(iter != NULL){
            count++;
            iter = iter->next;
        }
        k %= count;
        k = count - k;
        if(k == count){
            return head;
        }
        
        ListNode* tail = head;
        for(int i = 1; i < k; i++){
            tail = tail->next;
        }
        
        ListNode* newHead = tail->next;
        tail->next = NULL;
        
        iter = newHead;
        while(iter != NULL && iter->next != NULL){
            iter = iter->next;
        }
        iter->next = head;
        
        return newHead;
    }
};