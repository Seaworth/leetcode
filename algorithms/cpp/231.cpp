class Solution {
public:
    bool isPowerOfTwo(int n) {
        //思路：2的幂次方，转化为二进制，001,010,100,1000
        //只要统计1的个数为1，则返回true
        int cnt=0;
        while(n>0){
            cnt+=(n&1);
            n>>=1;
        }
        return cnt==1;
    }
};