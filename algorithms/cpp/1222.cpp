class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //思路：模拟，遍历queens数组，从八个方向查找，如果找到king，则保存到结果中
        //time: O(N)
        //space:O(1)
        vector<vector<int>> m(8, vector<int>(8));
        for(auto &q: queens){
            m[q[0]][q[1]]=1;
        }
        vector<vector<int>> ret;
        for(auto &q: queens){
            //双重for循环，模拟8个方向
            for(int i=-1;i<=1;++i){
                for(int j=-1;j<=1;++j){
                    if(i==0&&j==0) continue;
                    int x=q[0]+i;
                    int y=q[1]+j;
                    while(x>=0 && y>=0 && x<8 && y<8 && m[x][y]!=1 ){//判断边界，并且中间没有阻挡
                        if(x==king[0] && y==king[1]){
                            ret.push_back(q);
                        }
                        x+=i;
                        y+=j;                        
                    }
                }
            }
        }
        return ret;
    }
};