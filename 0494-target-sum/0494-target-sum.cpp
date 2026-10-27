class Solution {
public:
    int fn(int ind,int target,vector<int>& arr,vector<vector<int>>&dp){
    if(ind == 0){
        if(arr[ind] == 0 && target == 0)return 2;
        if(target == 0 || arr[ind] == target)return 1;
        return 0;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int notTake = fn(ind-1,target,arr,dp);
    int take = 0;
    if(arr[ind]<=target)take = fn(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = notTake+take;
}

    int findTargetSumWays(vector<int>& arr, int target) {
       int n = arr.size();
        int totSum = 0;
        for(int i =0;i<n;i++)totSum += arr[i];
        if(totSum-target <0  ||(totSum-target)%2 != 0)return 0;
        int diff = (totSum - target)/2;
        vector<vector<int>> dp(n,vector<int>(diff+1,-1));
        return fn(n-1,diff,arr,dp);
    }
};
