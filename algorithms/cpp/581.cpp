class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //思路：建立一个nums的副本，对其进行排序，然后首尾进行对比
        //time: O(N*logN)
        //space:O(N)
        vector<int> cnums(nums);
        sort(cnums.begin(), cnums.end());
        int i=0;
        int len=nums.size();
        while(i<len){
            if(nums[i]!=cnums[i]) break;
            ++i;
        }
        while(len>0){
            if(nums[len-1]!=cnums[len-1]) break;
            --len;
        }
        return len-i>0?len-i:0;
    }
};