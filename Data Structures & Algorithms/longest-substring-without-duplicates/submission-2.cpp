class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans = 0 , n = s.length();
      vector<int> v(257,0);
      int i = 0 , j = 0;
      while( j < n){
         while(v[s[j]]==1){
            v[s[i]]--;
            i++;
         }
         ans = max(ans,j-i+1);
         v[s[j]]++;
         j++;
        //  cout<<ans<<endl;
      }   
      return ans;
    }
};
