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
        ListNode* dupIter = head;
        ListNode* prev = NULL;
        ListNode* iter = head;
        while(iter != NULL){
            while(iter != NULL && iter->val == dupIter->val){
                iter = iter->next;
            }    
            if(iter != dupIter->next){
                if(prev != NULL){
                    prev->next = iter;
                }else{
                    head = iter;
                }
                while(dupIter != iter){
                    ListNode* tmp = dupIter;
                    dupIter = dupIter->next;
                    delete tmp;
                }
            }else{
                prev = dupIter;
                dupIter = iter;
            }
        }
        
        return head;
    }
};