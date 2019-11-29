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
    TreeNode* convertBST(TreeNode* root) {
        //方法1：中序遍历，但顺序是右子树→根→左子树，一直累加当前节点的值，并更新当前节点的值
        int sum=0;
        postOrder(root, sum);
        return root;        
    }
private:
    void postOrder(TreeNode* root, int &sum){
        if(!root) return;
        postOrder(root->right, sum);
        sum+=root->val;
        root->val=sum;
        postOrder(root->left, sum);
    }
};