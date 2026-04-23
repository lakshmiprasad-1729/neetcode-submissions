class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int i = 0 , j = n-1;
        while(i < j){
            ans = max(ans,((j-i)*min(heights[i],heights[j])));
            if(heights[i] <= heights[j]) i++;
            else j--;
        }
        // cout
        return ans;
    }
};
