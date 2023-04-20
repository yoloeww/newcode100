class Solution { //中序遍历法，迭代
  public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* last = nullptr;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (last) {
                    if (cur->val <= last->val)
                        return false;
                }
                last = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};
