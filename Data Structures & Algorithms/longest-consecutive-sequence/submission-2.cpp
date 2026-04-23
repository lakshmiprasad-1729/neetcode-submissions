class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int i = 0 , j = 1;
        int ans = 0;
        while( j < n ){
            int val = j-i;
            if(nums[i]+val == nums[j]){
                ans = max(ans,j-i+1);
            }
            else i=j;
            j++;
        }
        if(n > 0)ans = max(ans,1);
        return ans;
    }
};
