class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //思路：先排序，然后将排序好的数组，用两个指针，一个指向数组头，一个指向数组中间，将其赋值到另外一个数组中
        if(deck.size()<=1) return deck;
        sort(deck.begin(), deck.end());
        vector<int> ret(deck.size());
        int head=0;
        for(int i=0;i<deck.size();i+=2){
            ret[i]=deck[head++];
        }
        for(int i=1;i<deck.size();i+=2){
            ret[i]=deck[head++];
        }
        if(deck.size()%2==1){
            int half=deck.size()/2;
            int tmp=ret[half];
            ret[half]=ret[half-2];
            ret[half-2]=tmp;
        }
        return ret;
    }
};