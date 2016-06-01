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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        if(m == n)
            return head;
            
        ListNode* start = head;
        ListNode* end = head;
        ListNode* preTail = NULL;
        for(int i = 1; i < m; i++){
            preTail = start;
            start = start->next;
        }
        end = start;
        for(int j = m; j < n; j++){
            end = end->next;
        }
            
        ListNode* succHead = end->next;
        end->next = NULL;
        ListNode* prev = NULL;
        ListNode* iter = start;
        while(iter != NULL){
            ListNode* next = iter->next;
            iter->next = prev;
            prev = iter;
            iter = next;
        }
        if(preTail == NULL){
            head = prev;
        }else{
            preTail->next = prev;
        }
        start->next = succHead;
        
        return head; 
    }
    
};