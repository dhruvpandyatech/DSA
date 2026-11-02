class Solution {
public:
    int minDistance(string word1, string word2) {   
        int n = word1.size();
        int m = word2.size();

        int lcs = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    lcs = max(lcs,dp[i][j]);
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int minDel = (n-lcs);
        minDel+=m-lcs;
        return minDel;
    }
};