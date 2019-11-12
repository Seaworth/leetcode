class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //思路：滑动窗口，先找到最大子数组之和，最后返回最大平均数
        //time:O(N)
        //space:O(1)
        double maxSum=DBL_MIN;
        for(int i=0;i<k;++i){
            maxSum+=nums[i];
        }
        int tmp=maxSum;
        for(int i=1;i<nums.size()-k+1;++i){
            tmp=tmp-nums[i-1]+nums[i+k-1];//减去第i-1个数，加上第i+k-1个数
            if(tmp>maxSum) maxSum=tmp;
        }
        return maxSum/k;
    }
};