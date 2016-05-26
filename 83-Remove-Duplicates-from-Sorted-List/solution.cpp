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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        ListNode* last = head;
        
        while(node != NULL){
            while(node != NULL && node->val == last->val){
                node = node->next;
            }
            
            ListNode* tmp = last->next;
            last->next = node;
            
            while(tmp != NULL && tmp != node){
                ListNode* delPtr = tmp;
                tmp = tmp->next;
                delete delPtr;
            }
            
            last = node;
        }
        
        return head;
    }
};