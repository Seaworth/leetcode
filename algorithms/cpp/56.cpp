class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //思路：先对每个区间集合按照起始值排序，排完序后进行合并，遍历数组，先将第一个结果push到ret数组中，然后每次
        //判断当前区间的起始值是否大于ret数组中最后一个区间的末尾，如果大于，则将该区间压入ret中，如果小于，
        //则将ret中最后一个区间的末尾替换为最后一个区间的末尾值与当前末尾值的最大者。
        //time: O(N*logN)
        //space:O(N)
        if(intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });
        
        vector<vector<int>> ret;
        for(auto &interval: intervals){
            if(ret.empty() || interval[0]>ret.back()[1] ){
                ret.push_back(interval);
            }else{
                ret.back()[1]=max(interval[1], ret.back()[1]);
            }
        }
        return ret;
    }
};