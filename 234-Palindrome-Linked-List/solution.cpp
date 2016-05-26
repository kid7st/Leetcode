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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
            
        int count = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            count++;
        }
        
        ListNode* mid = head;
        for(int i = 0; i < count / 2 - 1; i++){
            mid = mid->next;
        }
        
        ListNode* back = mid->next;
        if(count % 2 == 1){
            back = back->next;
        }
        mid->next = NULL;
        
        ListNode* prev = NULL;
        while(back != NULL){
            ListNode* next = back->next;
            back->next = prev;
            prev = back;
            back = next;
        }
        
        back = prev;
        while(head != NULL && back != NULL){
            if(head->val != back->val)
                return false;
            head = head->next;
            back = back->next;
        }
        
        return true;
    }
};