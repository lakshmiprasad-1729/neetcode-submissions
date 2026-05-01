class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // if(amount==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e5));
        for(int i = 0 ; i <= n ; i++) dp[i][0]=0;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                int a = dp[i-1][j] , b = 1e5;
                if(j >= coins[i-1]) b = 1+dp[i][j-coins[i-1]];
                dp[i][j] = min(dp[i][j],min(a,b));
            }
        }
        cout<<dp[n][amount]<<endl;
        if(dp[n][amount] >=  1e5) return -1;
        return dp[n][amount];
    }
};
