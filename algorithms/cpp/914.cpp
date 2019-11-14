class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //思路：采用哈希表
        //time: ?
        //space:O(N)
        int len=deck.size();
        unordered_map<int,int> umap(len);
        for(int &d:deck){
            umap[d]++;
        }
        int mcd=-1;
        for(auto &um:umap){
            if(mcd==-1){
                mcd=um.second;
            }else{
                mcd=Max_Com_Divisor(mcd,um.second);
            }
        }
        return mcd>1;
    }
private:
    int Max_Com_Divisor(int a, int b){//更相减损法求最大公约数
        while(1){
            if(a>b){
                a-=b;
            }else if(a<b){
                b-=a;
            }else{
                return a;
            }
        }
    }
};