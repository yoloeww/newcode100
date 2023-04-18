
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};
*/class Solution {
public:
    bool recursion(TreeNode* root1, TreeNode* root2){
        //可以两个都为空
        if(root1 == nullptr && root2 == nullptr) 
            return true;
        //只有一个为空或者节点值不同，必定不对称
        if(root1 == nullptr || root2 == nullptr || root1->val != root2->val)
            return false;
        //每层对应的节点进入递归
        return recursion(root1->left, root2->right) && recursion(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        return recursion(pRoot, pRoot);
    }
};

