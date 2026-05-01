class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        int  l =-1 , r = -2;
        for(int i = 1 ; i <= n ; i++){
           for(int j = i ; j >= 1 ; j--){
              if(i==j){
                dp[i][j] =true; continue;
              }
              if((i-j+1)==2){
                 if(s[i-1]==s[j-1]){
                    dp[j][i] = true;
                   if((i-j+1) > (r-l+1)) r = i , l = j;
                 }
                 continue;
              }
              if( dp[j+1][i-1]){
                 if(s[i-1]==s[j-1]){
                    dp[j][i] = true;
                   if((i-j+1) > (r-l+1)) r = i , l = j;
                 }
              }
           } 
        }
        string ans = "";
        while( l <= r) ans += s[l-1],l++;
        if(ans == "") ans+= s[0];
        return ans;
    }
};
