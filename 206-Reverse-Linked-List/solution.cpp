/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* Recursive 
Time O(N)
Space O(N) recursive stack
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead;
        reverseList(head, &newHead);
        return newHead;
    }
    
private:
    ListNode* reverseList(ListNode* head, ListNode** finalHead){
        if(head == NULL){
            *finalHead = NULL;
            return NULL;
        }
        
        if(head->next == NULL){
            *finalHead = head;
            return head;
        }
        
        ListNode* back = reverseList(head->next, finalHead);
        back->next = head;
        back = back->next;
        back->next = NULL;
        
        return back;
    }
};