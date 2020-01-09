class Solution {
public:
    //思路：求全排列，通过递归dfs来求解，维持变量visited记录已经访问过的数
    //time: O(N!) space: O(N)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;//返回结果
        vector<int> visited(nums.size(), 0);//记录已经访问过的数
        vector<int> out;//记录每一个组合的变量
        dfs(nums, ret, visited, out, 0);
        return ret;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &visited, vector<int> &out, int level){
        if(level == nums.size()){//level表示组合中有的个数，如果等于了总的个数，就返回
            ret.push_back(out);return;
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]==1) continue;
            
            visited[i]=1;
            out.push_back(nums[i]);
            dfs(nums, ret, visited, out, level+1);
            out.pop_back();
            visited[i]=0;//弹出之后，标志数组要恢复为0
        }
    }
};