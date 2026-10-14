class Solution {
public:
    int memo(int n,vector<int> &dp){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = memo(n-1,dp) + memo(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return memo(n,dp);
    }
};