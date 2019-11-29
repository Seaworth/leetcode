class Solution {
public:
    #if 0
    void nextPermutation(vector<int>& nums) {
        //方法1：先从左往右遍历，找到a[i]<a[i+1]
        //再从左往右遍历，找到第一个大于a[i]的值a[j]，然后交换a[i]和a[i+1]
        //最后，将a[i+1]到a[end]的元素翻转，得到下一个字典序排列
        //小技巧：可以使用stl中的next_permutation算法，直接得到下一个排列
        int len=nums.size();
        int i=len-2;//倒数第二个数
        while(i>=0 && nums[i]>=nums[i+1]){
            --i;
        }
        if(i<0){//升序
            reverse(nums.begin(), nums.end());
        }else{
            int j=len-1;
            while(j>i && nums[j]<=nums[i]){
                --j;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
    #endif
    
    void nextPermutation(vector<int>& nums) {
        //方法2：可以使用stl中的next_permutation算法，直接得到下一个排列
        next_permutation(nums.begin(), nums.end());
    }
    
};