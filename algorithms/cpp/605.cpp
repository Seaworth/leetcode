class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //思路：贪心，遍历数组，只要数组这个位置为0，前后位置也都为0，则计数器加1，然后将这个位置设置为1，
        //数组第一个位置和最后一个位置，只需要相邻的数为0，则计数器加1
        //time: O(N)
        //space:O(1)
        int cnt=0;
        for(int i=0;i<flowerbed.size();++i){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0)  && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                flowerbed[i]=1;//设置为1
                ++cnt;
            }
        }
        return cnt>=n;
    }
};