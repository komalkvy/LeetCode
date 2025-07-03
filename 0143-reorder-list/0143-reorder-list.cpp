/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
       stack<ListNode*>st;
       ListNode* current=head;
       int length=0;
       while(current!=nullptr){
            st.push(current);
            current=current->next;
            length++;
       }
       current=head;
       int i=0;
       while(i<length/2){
        ListNode* temp=current->next;
        current->next=st.top();
        st.top()->next=temp;
        st.pop();
        i++;
        current=temp;
       }
       current->next=nullptr;
    }
};