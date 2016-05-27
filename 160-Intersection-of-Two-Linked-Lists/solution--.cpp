/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* tricky XOR
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        uintptr_t ptr = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        p = reverseList(p, ptr);
        q = reverseList(q, ptr);
        p = reverseList(p, ptr);
        
        //if no intersection
        if(q != headA)  
            q = reverseList(q, ptr);
            
        return reinterpret_cast<ListNode*> (ptr);
    }
    
private:
    ListNode *reverseList(ListNode *head, uintptr_t &accPtr) {
        ListNode* prev = NULL;
        while(head!= NULL) {
            accPtr ^= reinterpret_cast<uintptr_t> (head);
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};