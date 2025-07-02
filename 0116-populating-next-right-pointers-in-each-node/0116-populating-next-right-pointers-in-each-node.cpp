/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        deque<Node*> s;
        s.push_back(root);
        while(!s.empty()){
            int n=s.size();
            Node* prev=NULL;
            for(int i=0;i<n;i++){
                s[n-i-1]->next=prev;
                prev=s[n-i-1];
                Node* curr= s[i];
                if(curr->left) s.push_back(curr->left);
                if(curr->right) s.push_back(curr->right);
            }
            for(int i=0;i<n;i++){
                s.pop_front();
            }
        }
        return root;
    }
};