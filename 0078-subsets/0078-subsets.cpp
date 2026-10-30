class Solution {
public:
    void fn(int ind,int n,vector<int>& ds,vector<vector<int>>&ans,vector<int>&arr){
      if(ind == n){
        ans.push_back(ds);
        return;
      }  
      
    //   take 
        ds.push_back(arr[ind]);
        fn(ind+1,n,ds,ans,arr);
    //   not take 
        ds.pop_back();
        fn(ind+1,n,ds,ans,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        fn(0,n,ds,ans,nums);
        return ans;
    }
};
