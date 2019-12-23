class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //思路：定义两个变量i和j，i是遍历字符串中的字符，j是遍历字符串数组中的字符串，相当于把每个字符串上下排好，然后逐列遍历
        //如果某一个字符串遍历完了或该字符有不相等的字符串，说明当前就是最长子串
        if(strs.empty()) return "";
        int num=strs.size();
        int numStr1=strs[0].size();
        string ret="";
        for(int i=0;i<numStr1;++i){
            char ch=strs[0][i];
            for(int j=0;j<num;++j){
                if(strs[j].size()==i || strs[j][i]!=ch) return ret;
            }
            ret.push_back(ch);
        }
        return ret;
    }
};