class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int a = 0 , b = 0;
        for(int i = 0 ; i < n-1 ; i++){
            int curr = max(b,a+nums[i]);
            a = b , b = curr;
        }
        int c = 0 , d = 0;
        for(int i =  1 ; i < n ; i++){
            int curr = max(d,c+nums[i]);
            c=d  ,d = curr;
        }
        return max(max(a,b),max(c,d));
    }
};
