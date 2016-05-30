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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* resIter = NULL;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(res == NULL){
                res = new ListNode(sum);
                resIter = res;
            }else{
                resIter->next = new ListNode(sum);
                resIter = resIter->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(res == NULL){
                res = new ListNode(sum);
                resIter = res;
            }else{
                resIter->next = new ListNode(sum);
                resIter = resIter->next;
            }
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(res == NULL){
                res = new ListNode(sum);
                resIter = res;
            }else{
                resIter->next = new ListNode(sum);
                resIter = resIter->next;
            }
            l2 = l2->next;
        }
        
        if(carry != 0){
            if(res == NULL){
                res = new ListNode(carry);
                resIter = res;
            }else{
                resIter->next = new ListNode(carry);
                resIter = resIter->next;
            }
        }
        
        return res;
    }
};