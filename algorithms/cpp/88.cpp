class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //方法1
        //思路：合并nums1和nums2，再排序
        //time: O((m+n)log(m+n))
        //space:O(1)
        #if 0
        for(int i=0;i<n;++i){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        #endif
        
        //方法2
        //思路：双指针（从前往后）
        //time: O(m+n)
        //space:O(m)
        #if 0
        vector<int> nums1_copy(m,0);
        copy(nums1.begin(), nums1.begin()+m, nums1_copy.begin());
        int p1=0, p2=0, p=0;
        while(p1<m && p2<n){
            nums1[p++]=nums1_copy[p1]<nums2[p2] ? nums1_copy[p1++] : nums2[p2++];
        }
        if(p1<m){
            while(p1<m){
                nums1[p++]=nums1_copy[p1++];
            }
        }
        if(p2<n){
            while(p2<n){
                nums1[p++]=nums2[p2++];
            }
        }
        #endif
        
        //方法3
        //思路：双指针（从后往前）
        //time: O(m+n)
        //space:O(1)
        int p1=m-1, p2=n-1, p=nums1.size()-1;
        while(p1>=0 && p2>=0){
            nums1[p--]=nums1[p1]>nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        if(p2>=0){
            while(p2>=0){
                nums1[p--]=nums2[p2--];
            }
        }
    }
};