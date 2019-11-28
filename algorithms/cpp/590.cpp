/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#if 0
class Solution {
public:
    vector<int> postorder(Node* root) {
        //方法1：后序遍历，先访问子树，再访问根节点，递归
        //time: O(N)
        //space:O(N)
        if(root==NULL) return {};
        for(auto &c: root->children){
            postorder(c);
        }
        ret.push_back(root->val);
        return ret;
    }
private:
    vector<int> ret;
};
#endif

class Solution {
public:
    vector<int> postorder(Node* root) {
        //方法2：采用迭代，利用栈
        if(!root) return {};
        vector<int> ret;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* tmp = s.top();
            s.pop();
            ret.push_back(tmp->val);
            for(auto c: tmp->children){
                s.push(c);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};