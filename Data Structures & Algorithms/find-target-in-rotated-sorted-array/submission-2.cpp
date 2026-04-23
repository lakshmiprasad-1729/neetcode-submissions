class Solution {
public:
    int bns(int i,int j,int t,vector<int>& nums){
       int l = i , r = j;
       while(l <= r){
         int m = (l+r)/2;
         if(nums[m]==t) return m;
         else if(nums[m] < t) l = m+1;
         else r = m-1;
       }
       return -1;
    }
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int i = 0 , j = n-1;
        while( i < j){
            int m = (i+j)/2;
            if(nums[m] < nums[j]) j = m;
            else i = m+1;
        }
        cout<<i<<endl;
         int ans = -1;
         ans = max(ans,bns(0,i-1,t,nums));
         ans = max(ans,bns(i,n-1,t,nums));
         return ans;
        
    }
};
