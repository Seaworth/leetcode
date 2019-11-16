class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //思路：遍历，用两个哈希表存储已经遍历的值和k-diff中较小的数
        //time: O(N)
        //space:O(N)
        if(k<0) return 0;//绝对值不能为负数
        unordered_set<int> uset, diff;
        for(int &n:nums){
            if(uset.count(n+k)) diff.insert(n);
            if(uset.count(n-k)) diff.insert(n-k);
            uset.insert(n);
        }
        return diff.size();
    }
};