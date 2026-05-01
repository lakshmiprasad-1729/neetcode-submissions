class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string,int> hmap;
        int m = wordDict.size();
        for(int i = 0 ; i < m ; i++) hmap[wordDict[i]]++;
          vector<bool> dp(n+1,false); dp[0]=true;
         for(int i = 1 ; i <= n ; i++){
            string temp ="";
            for(int j = i ; j >= 1 ; j--){
                temp = s[j-1]+temp;
                if(hmap.find(temp) != hmap.end()){
                    dp[i] = dp[i] | dp[j-1];
                }
            }
         }
        return dp[n];
    }
};
