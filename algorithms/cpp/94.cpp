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
//方法1：递归，左→根→右
//time: 最坏的情况O(N)，通常情况O(h)，h是树的高度
//space:O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inOrder(root, ret);
        return ret;
    }
private:
    void inOrder(TreeNode* root, vector<int> &ret){
        if(!root) return;
        inOrder(root->left, ret);
        ret.push_back(root->val);
        inOrder(root->right, ret);        
    }
};
#endif

//方法2：采用栈，先将根节点压入栈中，再将其所有左子节点压入栈，然后弹出栈顶节点，
//将其值保存，然后再访问该节点的右子节点，若右子节点存在，下次循环将其所有左子节点压入栈中。
//这样保证了，左→根→右
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur || !s.empty()){//跳出时，最后的叶子节点的右子节点为NULL，并且栈s为空
            while(cur){//保存当前节点的所有左子树
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();s.pop();
            ret.push_back(cur->val);
            cur=cur->right;
        }
        return ret;
    }
};