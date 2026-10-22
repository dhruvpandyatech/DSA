class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        int i = 0;
        for(int j = 0;j<n;j++){
            dp[i][j] = matrix[i][j];
        }        
        
        for(int i = 1;i<n;i++){
            int lc = INT_MAX;
            int up = INT_MAX;
            int rc = INT_MAX;
            for(int j = 0;j<n;j++){
                up = dp[i-1][j];
               if(j-1>=0) lc = dp[i-1][j-1];
               if(j+1<n) rc = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(up,min(lc,rc));
            }
        }
        i = n-1;
        for(int j = 0;j<n;j++){
            mini = min(dp[i][j],mini);
        }
        return mini;
    }
};