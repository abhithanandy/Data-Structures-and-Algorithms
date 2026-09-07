class BSTIterator {
public:
    vector<int> arr;
    int index = 0;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        return arr[index++];
    }

    bool hasNext() {
        return index < arr.size();
    }
};