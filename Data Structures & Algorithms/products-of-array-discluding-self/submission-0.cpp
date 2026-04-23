class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans(n);
       long long prod =1 , val = 1;
       int cnt = 0;
       for(int i = 0 ; i < n ; i++){
         if(nums[i] != 0) val = 1LL*val*nums[i];
         else  cnt++;
         prod = 1LL*prod*nums[i];
       }
       for(int i = 0 ; i < n ; i++){
         if(cnt > 1){
           ans[i] = 0; continue;
         }

         if(nums[i]==0){
            ans[i] = (val); continue;
         }

         ans[i] = (prod/nums[i]);
       }

       return ans;
    }
};
