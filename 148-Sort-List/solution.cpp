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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* pivot = partition(head);
        
        return mergeList(sortList(head), 
                    sortList(pivot)
                );
    }
    
private:
    ListNode* partition(ListNode* head){
        //partition
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return slow;
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right){
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        ListNode* head = NULL;
        if(left->val < right->val){
            head = left;
            left = left->next;
        }else{
            head = right;
            right = right->next;
        }
        
        ListNode *iter = head;
        while(left != NULL || right != NULL){
            if(left != NULL && right != NULL){
                if(left->val < right->val){
                    iter->next = left;
                    left = left->next;
                    iter = iter->next;
                }else{
                    iter->next = right;
                    right = right->next;
                    iter = iter->next;
                }
            }else if(left != NULL){
                iter->next = left;
                left = left->next;
                iter = iter->next;
            }else if(right != NULL){
                iter->next = right;
                right = right->next;
                iter = iter->next;
            }
        }
        
        return head;
    }
};