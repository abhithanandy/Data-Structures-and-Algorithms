class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) {
            return nullptr;
        }

        // Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        else {
            // Case 1: No left child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children

            // Find inorder successor
            TreeNode* temp = root->right;

            while (temp->left != nullptr) {
                temp = temp->left;
            }

            // Replace value
            root->val = temp->val;

            // Delete successor
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
