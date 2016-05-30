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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow-> next;
            
            if(slow == fast)
                break;
        }
        
        //no circle
        if(slow != fast)
            return NULL;
        
        //find the entry point of the circle
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};