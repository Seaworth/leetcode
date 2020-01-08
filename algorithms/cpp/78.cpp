class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //思路：可以一位一位叠加求得所有的子集
        vector<vector<int>> ret(1);//里面包含一个[]
        int len = nums.size();
        for(int i=0; i<len; ++i){
            int len2 = ret.size();
            for(int j=0; j<len2; ++j){
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
};