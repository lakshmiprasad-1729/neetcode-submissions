class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hmap;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) hmap[nums[i]]++;
         vector<pair<int,int>> v;
        for(auto it:hmap){
          v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        int m = v.size();
        for(int i =  m-1 ; i >= 0 ; i--){
            if(k==0) break;
            ans.push_back(v[i].second);
            k--;
        }
        return ans;
    }
};
