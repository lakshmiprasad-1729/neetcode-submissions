class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector<string> v = strs;
        for(int i = 0 ; i < n ; i++){
            sort(v[i].begin(),v[i].end());
        }
        
        vector<bool> dp(n,false);

        for(int i = 0 ;i < n ; i++){
            if(dp[i]) continue;
            vector<string> temp = {strs[i]};
             dp[i] = true;
            for(int j = i+1 ; j < n ; j++){
               if(dp[j]) continue;
               if(v[i]==v[j]){
                temp.push_back(strs[j]); dp[j]= true;
               }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
