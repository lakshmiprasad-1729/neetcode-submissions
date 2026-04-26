class Solution {
public:
    set<vector<int>> s;
    void dfs(vector<int>& nums,int ind,int t,vector<int> val){
        if(t==0){
            sort(val.begin(),val.end());
            s.insert(val);
            return;
        }

        int n = nums.size();
        if(ind >= n || t < 0) return ;
        dfs(nums,ind+1,t,val);
        val.push_back(nums[ind]);
        dfs(nums,ind,t-nums[ind],val);
        // val.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> val;
        // sort(nums.begin(),nums.end());
        dfs(nums,0,target,val);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
