class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {
            int n = q.size();

            unsigned long long first = q.front().second;
            unsigned long long last = 0;

            for (int i = 0; i < n; i++) {
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                unsigned long long index = curr.second - first;

                last = index;

                if (node->left) {
                    q.push({node->left, 2 * index});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }

            ans = max(ans, last + 1);
        }

        return ans;
    }
};
