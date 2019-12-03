class Solution {
public:
    bool canJump(vector<int>& nums) {
        //思路：贪心算法，这道题主要关注能否到达最后一个位置，只要关注能够到达的最远位置，维护一个变量maxLen，遍历数组
        //maxLen大于当前的下标值，就可以继续遍历；如果maxLen小于当前的下标值或者maxlen大于了数组的长度，跳出循环
        //time: O(N)
        //space:O(1)
        int maxLen=0, len=nums.size();
        for(int i=0;i<len;++i){
            if(maxLen < i || maxLen >= len-1) break;
            maxLen=max(maxLen, i+nums[i]);
        }
        return maxLen>=len-1;
    }
};