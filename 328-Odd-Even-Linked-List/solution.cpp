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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* oddHead = head;
        ListNode* oddIter = oddHead;
        
        head = head->next;
        if(head == NULL)
            return oddHead;
        ListNode* evenHead = head;
        ListNode* evenIter = evenHead;
        
        head = head->next;
        while(head != NULL){
            oddIter->next = head;
            oddIter = oddIter->next;
            head = head->next;
            
            if(head != NULL){
                evenIter->next = head;
                evenIter = evenIter->next;
                head = head->next;
            }
        }
        
        oddIter->next = evenHead;
        evenIter->next = NULL;
        
        return oddHead;
    }
};