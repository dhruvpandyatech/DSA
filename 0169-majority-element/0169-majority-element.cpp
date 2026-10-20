class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int cnt = 0;
        for(int i :nums){
            if(i == me){
                cnt++;
            }
            else if(i!=me){
                cnt--;
            }
            if(cnt <= 0){
                me = i;
                cnt =1;
            }
        }
        return me;
    }
};