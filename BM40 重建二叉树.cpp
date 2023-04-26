/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstrut(vector<int> &pre,vector<int> &vin,int &p,int inbegin,int inend) {
        if(inbegin > inend) {
            return nullptr;
        }
        int iroot = inbegin;
 
        auto root = new TreeNode(pre[p]);
 
        while (iroot <= inend) {
            if (pre[p] == vin[iroot]) {
                break;
            }
            iroot ++;
        }
        p ++;
        root -> left = reConstrut(pre, vin, p, inbegin, iroot - 1);
        root -> right = reConstrut(pre, vin, p, iroot + 1, inend);
        return root;
 
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pi = 0;
        return reConstrut(pre,vin,pi,0,vin.size() - 1);
    }
};

