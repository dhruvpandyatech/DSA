class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
        int maxProd = 1;
            for(int j =i;j<n;j++){
                maxProd = maxProd*nums[j];
                maxi = max(maxProd,maxi);
            }
        }
        return maxi;
    }
};