/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#if 0
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //方法1：递归
        //time: O(N) space: O(N)
        return inorder(root, NULL);
    }
private:
    TreeNode* inorder(TreeNode* root, TreeNode* pre){
        if(root==NULL) return pre;
        TreeNode* ret=inorder(root->left, root);
        root->left=NULL;
        root->right=inorder(root->right, pre);
        return ret;
    }
};
#endif
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //方法2：迭代
        //time: O(N) space: O(N)
        TreeNode *dummy=new TreeNode(-1), *pre=dummy;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();s.pop();
            pre->right=root;
            pre=pre->right;
            root->left=NULL;
            root=root->right;
        }
        return dummy->right;
    }
};
