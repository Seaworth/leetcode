class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        //思路：遍历
        //time: O(N)
        //space:O(1)
        if(nums.size()<=1) return true;
        int cnt=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<nums[i-1]){
                if(i-2<0||nums[i]>nums[i-2]){
                    nums[i-1]=nums[i];
                }else{
                    nums[i]=nums[i-1];
                }
                ++cnt;
                if(cnt>1) return false;
            }
            
        }
        return true;
    }
};