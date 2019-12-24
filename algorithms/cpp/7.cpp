class Solution {
public:
    #if 0
    //方法1
    int reverse(int x) {
        //思路：用long类型的变量维持翻转的值，然后判断是否溢出
        long ret = 0;
        while(x){
            ret=ret*10+x%10;
            x/=10;
        }
        return ( ret<INT_MIN || ret>INT_MAX )? 0 : ret;
    }
    #endif
    
    //方法2：不用long变量，每次判断反转的值是否大于INT_MAX/10或等于INT_MAX且加数小于INT_MAX%10，
    //是否小于INT_MIN或等于INT_MIN且加数小于INT_MIN%10
    int reverse(int x){
        int ret=0;
        int posLastBit = INT_MAX%10;
        int negLastBit = INT_MIN%10;
        while(x!=0){
            int bit=x%10;
            x/=10;
            if(ret>INT_MAX/10 || ret==INT_MAX&&bit>posLastBit) return 0;
            if(ret<INT_MIN/10 || ret==INT_MIN&&bit<negLastBit) return 0;
            ret=ret*10+bit;
        }
        return ret;
    }
    
};