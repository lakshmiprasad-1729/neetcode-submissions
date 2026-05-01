class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
      int ans =-10 ;
      int i = 0 , j = 0;
      int a = 1 , b = 1 , c = 1;
      while(j < n){
        if(nums[j]==0){
           ans = max(ans,0);
        //    cout<<j-i<<" "<<b<<endl;
           if(j-i >= 1) ans = max(ans,b);
           if(j-i > 1) ans = max(ans,max(b/a,b/c));
           a=b=c=1;
           i=j+1;
           j++;
           continue;
        }
        if(a > 0) a*=nums[j];
        b*=nums[j]; c*=nums[j];
        if(nums[j] < 0) c = nums[j];
        j++;
      }
       if(j-i >= 1) ans = max(ans,b);
           if(j-i > 1) ans = max(ans,max(b/a,b/c));
    return ans;
    }
};
