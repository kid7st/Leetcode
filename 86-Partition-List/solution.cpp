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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = NULL;
        ListNode* lessIter = NULL;
        ListNode* greaterHead = NULL;
        ListNode* greaterIter = NULL;
        
        while(head != NULL){
            if(head->val < x){
                if(lessHead == NULL){
                    lessHead = head;
                    lessIter = lessHead;
                }else{
                    lessIter->next = head;
                    lessIter = lessIter->next;
                }
            }else{
                if(greaterHead == NULL){
                    greaterHead = head;
                    greaterIter = greaterHead;
                }else{
                    greaterIter->next = head;
                    greaterIter = greaterIter->next;
                }
            }
            head = head->next;
        }
        
        if(greaterIter != NULL){
            greaterIter->next = NULL;
        }
        
        if(lessIter != NULL){
            lessIter->next = greaterHead;
        }else{
            return greaterHead;
        }
        
        return lessHead;
    }
};