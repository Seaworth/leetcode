
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //思路：排序，遍历，双指针，剪枝（考虑特殊情况）
        //time: O(N^2)
        int len = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        if(len<3 || nums.front()>0 || nums.back()<0) return ret;
        for(int i=0;i<len-2;++i){
            if(nums[i]>0) break; 
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1, right=len-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    if(left==i+1 || right==len-1){
                       ret.push_back({nums[i], nums[left], nums[right]}); 
                       ++left; 
                       --right; 
                    }else if(nums[left]==nums[left-1]){
                        ++left;
                    }else if(nums[right]==nums[right+1]){
                        --right;
                    }else{
                       ret.push_back({nums[i], nums[left], nums[right]}); 
                       ++left;
                       --right; 
                    }
                }else if(sum<0){
                    ++left;
                }else{
                    --right;
                }
            }
        }
        return ret;
    }
};