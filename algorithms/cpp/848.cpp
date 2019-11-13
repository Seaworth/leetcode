class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        //思路：遍历所有情况
        //time: O(m*n)
        //space:O(1)
        int raw=grid.size();
        int col=grid[0].size();
        int cnt=0;
        for(int i=0;i<raw-2;++i){
            for(int j=0;j<col-2;++j){
                if(isMagic(grid, i, j)) ++cnt;
            }
        }
        return cnt;
    }
    
private:
    bool isMagic(vector<vector<int>> &grid, int r, int c){
        vector<int> raws(3,0);
        vector<int> cols(3,0);
        vector<int> exps(3,15);
        int dig=0;//正对角元素
        if(grid[r][c]==grid[r][c+1]) return false;//防止有9个相同的数
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                int val=grid[r+i][c+j];
                if(val<=0||val>9) return false;
                raws[i]+=val;
                cols[j]+=val;
                if(i==j) dig+=val;
            }
        }
        if(raws==exps && cols==exps && dig==15){
            return true;
        }else{
            return false;
        }
        
    }
};