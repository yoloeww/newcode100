class Solution {
public:
    class returnType {
    public:
        bool balance;
        int height;
        returnType(bool balance,int height) : balance(balance), height(height)
        {}
    };
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        return process(pRoot).balance;
    
    }
    returnType process(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return returnType(true,0);
        returnType leftdata = process(pRoot -> left);
        returnType rightdata =  process(pRoot -> right);
        int height = max(leftdata.height,rightdata.height) + 1;

        bool balance = leftdata.balance && rightdata.balance && abs(rightdata.height - leftdata.height) < 2;
        return returnType(balance,height);
    }
};
