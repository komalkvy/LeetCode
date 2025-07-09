class Solution {
public:
    TreeNode* findMin(TreeNode* node){
        while(node->left){
            node=node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left, key);
        }
        else{
            if(!root->left&&!root->right){
                delete(root);
                return nullptr;
            }
            else if(!root->left){
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            else if(!root->right){
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else{
                TreeNode* temp=findMin(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);

            }
        }
        return root;
    }
};