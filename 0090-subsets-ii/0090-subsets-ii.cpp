class Solution {
public:
    void subsets(vector<int>& ds,set<vector<int>>& ans,vector<int>& nums,int idx,int n){
            ans.insert(ds);
            if(idx >= n){
                return;
            }
            ds.push_back(nums[idx]);
            subsets(ds,ans,nums,idx+1,n);
            ds.pop_back();
            subsets(ds,ans,nums,idx+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ds;
        set<vector<int>> ans;
        subsets(ds,ans,nums,0,n);
        vector<vector<int>> fans(ans.begin(),ans.end());
        return fans;
    }
};