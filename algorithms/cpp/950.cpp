class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //思路：模拟法，通过queue保存数组deck的下标，从而实现模拟卡牌取牌的过程
        //[0,2,4,6,...]，通过pop移除已经复制的元素下标，队尾push下一个元素，就是将牌放到底部
        //time: O(N*logN)
        //space:O(N)
        int len = deck.size();
        queue<int> index;
        for(int i=0;i<len;++i){
            index.push(i);
        }
        vector<int> ret(len);
        sort(deck.begin(), deck.end());
        for(int i=0;i<len;++i){
            ret[index.front()]=deck[i];
            index.pop();
            index.push(index.front());
            index.pop();
        }
        return ret;
    }
};