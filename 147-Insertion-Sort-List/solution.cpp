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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortedHead = NULL;
        while(head != NULL){
            ListNode* node = head;
            head = head->next;
            
            ListNode* des = findPos(sortedHead, node->val);
            if(des == NULL){
                node->next = sortedHead;
                sortedHead = node;
            }else{
                insert(des, node);
            }
        }
        
        return sortedHead;
    }
    
private:
    ListNode* findPos(ListNode* sortedHead, int val){
        ListNode* destination = NULL;
        ListNode* iter = sortedHead;
        while(iter != NULL && iter->val < val){
            destination = iter;
            iter = iter->next;
        }
        
        return destination;
    }
    
    void insert(ListNode* destination, ListNode* item){
        item->next = destination->next;
        destination->next = item;
        return;
    }
};