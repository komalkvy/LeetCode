class Solution {
    private:
        vector<int> nodes;
    public:
        Solution(ListNode* head) {
            while (head != nullptr) {
                nodes.push_back(head->val);
                head = head->next;
            }
        }
        
        int getRandom() {
            int i = rand() % nodes.size();
            return nodes[i];
        }
};