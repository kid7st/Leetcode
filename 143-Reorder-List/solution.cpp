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
    void reorderList(ListNode* head) {
        ListNode* mid = partition(head);
        mid = reverseList(mid);
        merge(head, mid);
    }
    
private:
    ListNode* partition(ListNode* head){
        if(head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if(fast == NULL){
            prev->next = NULL;
            return slow;
        }else{
            prev = slow;
            slow = slow->next;
            prev->next = NULL;
            return slow;
        }
    }    
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* iter = head;
        while(iter != NULL){
            ListNode* next = iter->next;
            iter->next = prev;
            prev = iter;
            iter = next;
        }
        
        return prev;
    }
    
    ListNode* merge(ListNode* first, ListNode* second){
        if(first == NULL)
            return second;
        if(second == NULL)
            return first;
        ListNode* head = first;
        first = first->next;
        ListNode* iter = head;
        iter->next = second;
        second = second->next;
        iter = iter->next;
        
        while(first != NULL && second != NULL){
            iter->next = first;
            first = first->next;
            iter = iter->next;
            
            iter->next = second;
            second = second->next;
            iter = iter->next;
        }
        
        if(first != NULL){
            iter->next = first;
            first = first->next;
            iter = iter->next;
        }
        
        return head;        
    }
};
