class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<int> dp(n+1,0); dp[n-1] = 1;

        for(int i = n-2 ; i >= 0 ; i--){
           if(i+nums[i] >= n-1){
            dp[i] = 1+dp[i+1];
            continue;
           }
           if(dp[i+1]-dp[i+nums[i]+1] > 0 && nums[i] != 0) dp[i] = 1+dp[i+1];
           else dp[i] = dp[i+1];
        }

        //  for(int i = 0 ; i < n ; i++) cout<<dp[i]<<" ";
        //  cout<<endl;
        if(dp[0]==dp[1]) return false;
        return true;
    }
};
