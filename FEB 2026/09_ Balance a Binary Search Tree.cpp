class Solution {
public:
    void inorder(TreeNode* root, vector<int>& val) {
        if (!root)
         return;

        inorder(root->left, val);
        val.push_back(root->val);
        inorder(root->right, val);
    }

    TreeNode* build(int left, int right, vector<int>& val) {
        if (left > right)
         return NULL;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(val[mid]);
        root->left  = build(left, mid - 1, val);
        root->right = build(mid + 1, right, val);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> val;
        inorder(root, val);

        int left = 0;
        int right = val.size() - 1;

        return build(left, right, val);
    }
};
