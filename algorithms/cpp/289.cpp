class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //time: O(row*col) space: O(1)
        int row=board.size();
        if(row<=0) return;
        int col=board[0].size();
        
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                
                int lives=0;//活着的细胞,包含自己
                for(int x=max(0, i-1);x<min(row, i+2);++x){
                    for(int y=max(0, j-1);y<min(col, j+2);++y){
                        lives+=board[x][y]&1;//&1的目的是只取board的最低位，因为有可能board是更新后的状态
                    }
                }
                
                //如果活细胞周围有2,3个活细胞，或者死细胞周围有3个活细胞
                int cell=board[i][j];
                if((cell==1&&(lives==3||lives==4)) || (cell==0&&lives==3) ){
                    board[i][j] |= 0b10;//保存下一个状态到前一个bit
                }                
            }
        }
        
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                board[i][j]>>=1;//转移到下一个状态
            }
        }
    }
};