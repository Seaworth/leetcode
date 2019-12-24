class Solution {
public:
    bool canWinNim(int n) {
        //思路：n=4时，第一个人无论拿多少个，第二个人都可以取胜
        //1*4<n<2*4（n=5,6,7）时，第一个人总是可以拿掉一定数量的石头，使剩下的数量为4，从而第一个人获胜
        //n=8时，第一个人无论拿多少，第二个人总是可以拿掉一定数量的石头，使剩下的数量为4，从而第一个人失败
        //2*4<n<3*4（n=9,10,11）时，第一个人可以拿掉一定数量的石头，使剩下的数量为8，从而第一个人获胜
        //time: O(1) space: O(1)
        return n%4!=0;
    }
};