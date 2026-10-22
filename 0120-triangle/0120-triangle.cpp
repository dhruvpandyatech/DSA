class Solution {
public:
    int fn(int i,int j,int n,vector<vector<int>> &a,vector<vector<int>> &dp){
        if(i>n)return 1e9;
        if(dp[i][j] != 1e5)return dp[i][j];
        int down = fn(i+1,j,n,a,dp);
        int rc = fn(i+1,j+1,n,a,dp);

        return dp[i][j] = a[i][j] + min(down,rc);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,1e5));
        int i = m-1;
        for(int j = 0;j<m;j++){
            dp[i][j] = triangle[i][j];
        }
        return fn(0,0,m-1,triangle,dp);
    }
};
