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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = NULL;
        while(head != NULL && head->val == val){
            prev = head;
            head = head->next;
            delete prev;
        }
        
        if(head == NULL)
            return head;
            
        ListNode* node = head->next;
        prev = head;
        while(node != NULL){
            if(node->val == val){
                ListNode* tmp = node;
                node = node->next;
                prev->next = node;
                delete tmp;
            }else{
                prev = node;
                node = node->next;
            }
        }
        
        return head;
    }
};