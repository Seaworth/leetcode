class Solution {
public:
    bool isValid(string s) {
        //思路：利用一个栈，不断地往里压左括号，一旦遇上了一个右括号，我们就把栈顶的左括号弹出来，表示这是一个合法的组合，
        //以此类推，直到最后判断栈里还有没有左括号剩余。
        //time: O(N)，因为遍历每个字符，栈的push和pop操作的复杂度为O(1)
        //space:O(N)，最坏的情况，需要进行N次push操作，'[[[[['
        //PS：可以采用unorder_map保存键值对，简化代码
        unordered_map<char, char> umap;
        umap[')']='(';
        umap['}']='{';
        umap[']']='[';
        
        stack<char> st;
        for(auto &c:s){
            
            if(umap.find(c)!=umap.end()){
                //]})
                if(st.empty()) return false;
                char topElem=st.top();
                if(topElem==umap[c])
                    st.pop();
                else
                    return false;
            }else{
                //({[
                st.push(c);
                cout<<c<<"-";
            }
        }
        return st.empty();            
    }
};