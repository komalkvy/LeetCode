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
    void deleteNode(ListNode* node) {
        ListNode* t1 = node ;
         ListNode* t2 = node->next;
      
         while(t2->next!=NULL){ 
            t1->val = t2->val; 
            t1 = t2 ; 
            t2 = t2->next;
         } 
           if(t2->next==NULL){ 
            t1->val = t2->val;
        }
         t1->next = NULL;
          delete(t2);
    }
};