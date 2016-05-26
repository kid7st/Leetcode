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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
            
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++)
            fast = fast->next;
            
        ListNode* prev;
        while(fast != NULL){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        if(slow == head){
            head = head->next;
        }else{
            prev->next = slow->next;
        }
        delete slow;
        
        return head;
    }
};