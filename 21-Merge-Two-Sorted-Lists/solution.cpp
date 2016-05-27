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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
            
        ListNode* head;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }
        
        ListNode* node = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        
        while(l1 != NULL){
            node->next = l1;
            l1 = l1->next;
            node = node->next;
        }
        
        while(l2 != NULL){
            node->next = l2;
            l2 = l2->next;
            node = node->next;
        }
        
        return head;
    }
};