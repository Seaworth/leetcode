class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //思路：维护一个长度为3的set
        //time: O(N)
        //space:O(1)
        set<int> mySet;
        for(int &n:nums){
            mySet.insert(n);
            if(mySet.size()>3){
                mySet.erase(mySet.begin());
            }
        }
        if(mySet.size()>=3){
            return *mySet.begin();
        }else{
            return *mySet.rbegin();
        }
    }
};