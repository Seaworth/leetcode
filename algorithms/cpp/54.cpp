class Solution {
public:
    #if 0
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //方法1：模拟螺旋的轨迹
        //time: O(N) N是matrix中的元素个数
        //space:O(N)
        if(matrix.size()<=0) return {}; 
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<int>> seen(row, vector<int> (col,0));
        vector<vector<int>> delta={{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> ret;
        int x=0, y=0, c=0;
        for(int i=0;i<row*col;++i){
            ret.push_back(matrix[x][y]);
            seen[x][y]=1;
            int next_x=x+delta[c][0];
            int next_y=y+delta[c][1];
            if(next_x>=0 && next_x<row && next_y>=0 && next_y<col && seen[next_x][next_y]!=1){
                x=next_x;
                y=next_y;
            }else{
                ++c;
                c=c%4;
                x+=delta[c][0];
                y+=delta[c][1];
            }
        }
        return ret;
    }
    #endif
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //方法2：模拟螺旋，缩小边界，不用存储遍历过的标志位
        //time: O(N) N是matrix中的元素个数
        //space:O(1)
        if(matrix.empty() || matrix[0].empty()) return {};//处理边界 
        int row=matrix.size(), col=matrix[0].size();
        vector<int> ret;
        int up=0, down=row-1, left=0, right=col-1;
        while(1){
            for(int i=left;i<=right;++i) ret.push_back(matrix[up][i]);
            if(++up > down) break;//因为up→down，0→row-1，故当up大于down时，跳出
            for(int i=up;i<=down;++i) ret.push_back(matrix[i][right]);
            if(--right < left) break;//因为right→left，col-1→0，故当right小于left时，跳出
            for(int i=right;i>=left;--i) ret.push_back(matrix[down][i]);
            if(--down < up) break;//因为down→up，row-1→0，故当down小于up时，跳出
            for(int i=down;i>=up;--i) ret.push_back(matrix[i][left]);
            if(++left > right) break;//因为left→right，0→col-1，故当left大于right时，跳出
        }
        return ret;
    }
};