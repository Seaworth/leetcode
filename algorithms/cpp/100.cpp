/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //思路：递归，先判断根是否为null，如果根相等，再判断左子树和右子树是否相等
        //time: O(N)
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) 
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};