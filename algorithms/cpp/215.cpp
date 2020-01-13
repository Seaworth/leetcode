class Solution {
public:
    #if 0
    //思路：先排序，然后取第k大的数
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
    #endif
    //思路：采用快速排序，当pivot的位置为k-1时，则返回nums[pivot]
    int findKthLargest(vector<int>& nums, int k) {
        int pos, left=0, right=nums.size()-1;
        while(1){
            pos=partition(nums, left, right);
            if(pos==k-1) return nums[pos];
            if(pos>k-1){
                right=pos-1;
            }else{
                left=pos+1;
            }
        }
    }
    int partition(vector<int>& nums, int &left, int &right){
        int pivot=nums[left], l=left+1, r=right;
        while(l<=r){
            if(pivot>nums[l]&&pivot<nums[r]){
                swap(nums[l], nums[r]);
                ++l;--r;
            }
            if(nums[l]>=pivot) ++l;
            if(nums[r]<=pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};