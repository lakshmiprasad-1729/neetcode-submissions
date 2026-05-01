class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 , prev2 ; prev1 = prev2 = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            int curr = 0;
            curr = max(nums[i]+prev1 , prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return max(prev1,prev2);
    }
};
