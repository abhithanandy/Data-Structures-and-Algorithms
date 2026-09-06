class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        // Find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Found the node
        else {

            // No left child
            if (root->left == NULL) {
                return root->right;
            }

            // No right child
            if (root->right == NULL) {
                return root->left;
            }

            // Two children
            TreeNode* temp = root->right;

            while (temp->left != NULL) {
                temp = temp->left;
            }

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};