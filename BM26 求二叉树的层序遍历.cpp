/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <vector>
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> res;
    void process(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur -> val);
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
            res.push_back(v);
        }
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        if (root == nullptr)
            return res;
        process(root);
        return res;
    }
};
