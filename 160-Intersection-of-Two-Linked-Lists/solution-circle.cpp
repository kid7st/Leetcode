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
        if(headA == NULL || headB == NULL)
            return NULL;
        
        bool aIsSwitched = false, bIsSwitched = false;
        ListNode *iterA = headA, *iterB = headB;
        
        while(true){
            if(iterA->next){
                iterA = iterA->next;
            }else{
                iterA = headB;
                aIsSwitched = true;
            }
            
            if(iterB->next){
                iterB = iterB->next;
            }else{
                iterB = headA;
                bIsSwitched = true;
            }
            
            if(aIsSwitched && bIsSwitched){
                if(iterA == iterB)
                    return iterA;
                    
                if(iterA->next == iterB->next)
                    return iterA->next;
            }
        }
        
        return NULL;
        
    }
};