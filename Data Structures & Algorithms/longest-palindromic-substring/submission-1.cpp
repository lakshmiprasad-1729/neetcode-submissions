class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string ans = "";
        for(int i = 1 ; i <= n ; i++){
            string a = "" , b = "";
            for(int j =  i ; j >= 1 ; j--){
                a = s[j-1]+a;
                b +=s[j-1];
                int val = i-j+1;
                dp[i][val] += dp[i-1][val];
                if(a==b){
                     dp[i][val]++;
                     if(ans.length() < a.length()) ans = a;
                }
            }
        }
        return ans;
    }
};
