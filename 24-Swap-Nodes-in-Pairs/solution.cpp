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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* pad = new ListNode(0);
        pad->next = head;
        
        ListNode* prev = pad;
        ListNode* node = head;
        
        while(node != NULL && node->next != NULL){
            ListNode* next = node->next;
            
            prev->next = next;
            node->next = next->next;
            next->next = node;
            
            prev = node;
            node = node->next;
        }
        
        head = pad->next;
        delete pad;
        return head;
    }
};