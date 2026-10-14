class Solution {
public:

    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
       int  prev2 = 1;
        int prev = 1;

        for(int i = 2;i<=n;i++){
            int curri = prev+prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};