class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //思路：维持变量dir控制上左下右四个方向
        //time: O(N*N) space: O(N*N)
        vector<vector<int>> ret(n, vector<int>(n));
        int dir=2;//初始方向为右
        int max_x=n-1, max_y=n-1, min_x=0, min_y=1;//min_y=1因为循环的时候返回来，方向向上的最后一行的下标为1
        int x=0, y=0;
        int val=1;
        while(val<=n*n){
            ret[y][x]=val++;
            switch (dir){
                case 1://up
                    --y;
                    if(y==min_y){
                        dir=2;
                        ++min_y;
                    }
                    break;
                case 2://right
                    ++x;
                    if(x==max_x){
                        dir=3;
                        --max_x;
                    }
                    break;
                case 3://down
                    ++y;
                    if(y==max_y){
                        dir=4;
                        --max_y;
                    }
                    break;
                case 4://left
                    --x;
                    if(x==min_x){
                        dir=1;
                        ++min_x;
                    }
                    break;
            }
        }
        return ret;
    }
};