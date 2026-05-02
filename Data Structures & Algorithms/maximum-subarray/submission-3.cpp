class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN , mini= 0 ;
        for(int i = 1 ; i <= n ; i++ ){
            sum +=nums[i-1];
            ans = max(ans,sum-mini);
            mini = min(mini,sum);
        }
        return ans;
    }
};
