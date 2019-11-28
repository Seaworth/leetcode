#if 0
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //思路：先对矩阵转置，然后翻转每一行
        //time: O(N*N)
        //space:O(1)
        int nrow=matrix.size();
        //转置
        for(int i=0;i<nrow;++i){
            for(int j=i+1;j<nrow;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //翻转每一行
        for(int i=0;i<nrow;++i){
            for(int j=0;j<nrow/2;++j){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][nrow-1-j];
                matrix[i][nrow-1-j]=temp;
            }
        }
    }
};
#endif

//用swap和reverse函数优化
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //思路：先对矩阵转置，然后翻转每一行
        //time: O(N*N)
        //space:O(1)
        int nrow=matrix.size();
        //转置
        for(int i=0;i<nrow;++i){
            for(int j=i+1;j<nrow;++j){
                swap(matrix[i][j], matrix[j][i]);//转置
            }
            reverse(matrix[i].begin(), matrix[i].end());//翻转
        }
    }
};