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
    vector<int> preorder(Node* root) {
        //方法1：采用递归实现
        if(root==NULL) return {};
        ret.push_back(root->val);
        for(int i=0;i<root->children.size();++i){
            preorder(root->children[i]);
        }
        return ret;
    }
private:
    vector<int> ret;
};
#endif

class Solution {
public:
    vector<int> preorder(Node* root) {
        //方法2：遍历
        if(root==NULL) return {};
        vector<int> ret;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* tmp=s.top();s.pop();
            ret.push_back(tmp->val);
            for(auto it=tmp->children.rbegin();it!=tmp->children.rend();++it){//用逆序的迭代器
                s.push(*it);
            }
        }
        return ret;
    }
};