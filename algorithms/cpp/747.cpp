    int dominantIndex(vector<int>& nums) {
        #if 0//方法一
        //思路：找到最大元素，遍历数组，是否有其他数字的两倍等于最大数字
        //time:O(N)
        //space:O(1)
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxInd = max_element(nums.begin(), nums.end())-nums.begin();
        for(int i=0;i<nums.size();++i){
            if(nums[i]*2>maxNum && i!=maxInd){
                return -1;
            }
        }
        return maxInd;
        #endif
        
        //方法二
        //思路：遍历找到最大值和第二大的值，判断第二大值的两倍是否大于最大值即可
        //time:O(N)
        //space:O(1)
        if(nums.size()<=1) return 0;
        int max=0, maxInd=0, secondMax=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>max){
                secondMax=max;
                max=nums[i];
                maxInd=i;                
            }else if(nums[i]>secondMax){
                secondMax=nums[i];
            }
        }
        return max>=secondMax*2?maxInd:-1;
    }
};