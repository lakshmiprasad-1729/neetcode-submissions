class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n+1,1); dp[0]= 0;

      for(int i = 1 ; i <= n ; i++){
        for(int j = i-1 ; j >= 1 ; j--){
           if(nums[j-1] < nums[i-1]) dp[i] = max(dp[i],1+dp[j]);
        }
      }   
      int ans = 0;
      for(int i = 0 ; i <= n ; i++) ans = max(ans,dp[i]);
      return ans;
    }
};
