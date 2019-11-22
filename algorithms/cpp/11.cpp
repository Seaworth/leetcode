class Solution {
public:
    int maxArea(vector<int>& height) {
        #if 0
        //方法1：暴力求解
        //time: O(N*N)
        //space:O(1)
        int ret=0;
        int len=height.size();
        for(int i=0;i<len-1;++i){
            for(int j=i+1;j<len;++j){
                int tmp=height[i]>height[j]?height[j]*(j-i):height[i]*(j-i);
                if(tmp>ret) ret=tmp;
            }
        }
        return ret;
        #endif
        
        //方法2：双指针，每次移动更短的那条边，向中间靠拢，因为只有移动短的那条边才会增加面积
        //如果移动长的那条边，就算下一次的边更长，面积也会按照短的一边计算，并且x轴的长度在减小
        //time: O(N)
        //space:O(1)
        int ret=0;
        int i=0, j=height.size()-1;
        int area=0;
        while(i<j){
            if(height[i]>=height[j]){
                area=height[j]*(j-i);
                --j;
            }else{
                area=height[i]*(j-i);
                ++i;
            }        
            if(area>ret) ret=area;
        }
        return ret;
    }
};