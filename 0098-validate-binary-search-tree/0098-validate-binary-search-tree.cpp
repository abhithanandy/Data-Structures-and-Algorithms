class Solution {
public:
    bool check(TreeNode* root, long long min, long long max) {
        if (root == NULL) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (!check(left, min, root->val)) {
            return false;
        }

        if (!check(right, root->val, max)) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};