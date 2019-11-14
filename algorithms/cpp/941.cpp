class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        //思路：直接遍历
        //time: O(N)
        //space:O(1)
        int i=0;
        int len=A.size();
        //up
        while(i<len-1 && A[i]<A[i+1]){
            ++i;
        }
        //顶点不能再第一个和最后一个位置
        if(i==0 || i==len-1) return false;
        //down
        while(i<len-1 && A[i]>A[i+1]){
            ++i;
        }
        return i==len-1;
    }
};