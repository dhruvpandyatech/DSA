class Solution {
public:
    int fn(int ind,int amount,vector<int>&coins,vector<vector<int>>& dp){
        if(amount == 0)return 1;
        if(ind ==0){
            if(amount%coins[ind] == 0)return 1;
            else return 0;
        }
        if(dp[ind][amount] != -1)return dp[ind][amount];
        int notTake = fn(ind-1,amount,coins,dp);
        int take = 0;
        if(coins[ind] <= amount)take = fn(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fn(n-1,amount,coins,dp);
    }
};






