class Solution {
public:
    void solve(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (root == NULL)
            return;

        if (ans.size() == level)
            ans.push_back(vector<int>());

        if (level % 2 == 0)
            ans[level].push_back(root->val);
        else
            ans[level].insert(ans[level].begin(), root->val);

        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        solve(root, 0, ans);

        return ans;
    }
};