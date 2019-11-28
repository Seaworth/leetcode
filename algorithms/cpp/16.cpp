class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //思路：先排序，遍历数组，固定当前遍历的元素，采用双指针逼近
        //time: 排序O(NlogN)，遍历O(N*N)，最终为O(N*N)
        //space:O(1)
        sort(nums.begin(), nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int err=abs(target-sum);
        for(int i=0;i<nums.size()-2;++i){
            int fix=nums[i];
            int l=i+1, r=nums.size()-1;
            while(l<r){
                int tmp=nums[i]+nums[l]+nums[r];
                if(tmp==target) return tmp;//如果相等，提前返回
                if(abs(target-tmp)<err){
                    sum=tmp;
                    err=abs(target-tmp);
                }
                if(tmp>target){
                    --r;
                }else{//tmp<target
                    ++l;
                }
            }
        }
        return sum;
    }
};