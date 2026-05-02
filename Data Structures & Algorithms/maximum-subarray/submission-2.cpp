class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        for(int i = 1 ; i <= n ; i++) pref[i] = pref[i-1]+nums[i-1];
        int ans = INT_MIN , mini= 0 ;
        for(int i = 1 ; i <= n ; i++ ){
            ans = max(ans,pref[i]-mini);
            mini = min(mini,pref[i]);
        }
        return ans;
    }
};
