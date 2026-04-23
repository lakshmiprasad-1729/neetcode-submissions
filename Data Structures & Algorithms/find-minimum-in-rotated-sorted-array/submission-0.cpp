class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int i = 0 , j =  n-1 , m ;
        while( i < j){
            m = (i+j)/2;
            if(nums[m] < nums[j]) j = m;
            else i = m+1;
            cout<<i<<" "<<j<<endl;
        } 
        return nums[i];
    }
};
