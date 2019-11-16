class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        #if 0
        //方法1：遍历，每次移动数组头的元素到末尾（超出时间限制）
        //time: O(N*K)
        //space:O(1)
        int len=nums.size();
        for(int i=0;i<k;++i){
            int tmp=nums[len-1];
            for(int j=len-2;j>=0;--j){
                nums[j+1]=nums[j];
            }
            nums[0]=tmp;
        }
        #endif
        
        //方法2：新建一个数组保存右移的元素，移动后，再拷贝回原数组
        //time: O(N)
        //space:O(N)
        int len=nums.size();
        vector<int> tmp(len,0);
        int j=0;
        for(int i=0;i<len;++i){
            tmp[(k+i)%len]=nums[i];
        }
        copy(tmp.begin(),tmp.end(),nums.begin());

    }
};