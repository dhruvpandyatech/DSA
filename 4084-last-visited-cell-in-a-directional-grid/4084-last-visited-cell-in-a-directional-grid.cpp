class Solution {
public:
    vector<int> solve(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited,vector<int>&ans){
        if(visited[i][j]==1){
            return ans;
        }
        // left
        if(grid[i][j] == 'L'){
            visited[i][j] =1;
            if(j>0){
                if(visited[i][j-1]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                solve(i,j-1,grid,visited,ans);
                }
            else {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            }
        // right
        if(grid[i][j] == 'R'){
            visited[i][j] =1;
            if(j<grid[0].size()-1){
                if(visited[i][j+1]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                solve(i,j+1,grid,visited,ans);
                }
            else {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            }
        
        // up
        if(grid[i][j] == 'U'){
            visited[i][j] =1;
            if(i>0){
                if(visited[i-1][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                solve(i-1,j,grid,visited,ans);
                }
            else {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            }
        // down
        if(grid[i][j] == 'D'){
            visited[i][j] =1;
            if(i<grid.size()-1){
                if(visited[i+1][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                solve(i+1,j,grid,visited,ans);
                }
            else {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            }

        return ans;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> ans;
        return solve(0,0,grid,visited,ans);
    }
};