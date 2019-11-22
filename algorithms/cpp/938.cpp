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
    int rangeSumBST(TreeNode* root, int L, int R) {
        //思路：对二叉树进行遍历，并且判断在[L, R]之间的数，将其累加到sum中
        //如果数大于R，只遍历左子树，如果数小于L，只遍历右子树
        //time: O(N)
        //space:O(H)
        InOrderTraverse(root, L, R);
        return sum;        
    }
private:
    int sum=0;
    void InOrderTraverse(TreeNode* root, int L, int R){
        if(root==NULL) return;
        if(root->val>=L && root->val<=R){
            sum+=root->val;
        }
        if(root->val<R){
            InOrderTraverse(root->right, L, R);
        }
        if(root->val>L){
            InOrderTraverse(root->left, L, R);
        }
    }
};