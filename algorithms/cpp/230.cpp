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
//方法1：递归:
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //思路：中序遍历，采用变量cnt计数，当计数等于k时，则返回
        return inorderTraverse(root, k);
    }
private:
    int cnt=0;
    int inorderTraverse(TreeNode* node, int &k){
        if(node==NULL) return 0;
        int leftVal = inorderTraverse(node->left, k);
        if(cnt==k) return leftVal;
        ++cnt;
        if(cnt==k) return node->val;
        return inorderTraverse(node->right, k);
    }
};
#endif

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //方法2：栈+迭代，中序遍历，采用变量cnt计数，当计数等于k时，则返回
        int cnt=0;
        stack<TreeNode*> s;
        TreeNode* p=root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top();s.pop();
            ++cnt;
            if(cnt==k) return p->val;
            p=p->right;
        }
        return 0;
    }
};