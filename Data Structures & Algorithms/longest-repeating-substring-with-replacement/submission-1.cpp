class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.length();
       vector<int> v(26,0);
       int ans = 0 , i = 0 , j = 0;
       while(j < n){
          v[s[j]-'A']++;
          int maxi = *max_element(v.begin(),v.end()) ,
            sum = accumulate(v.begin(),v.end(),0);
            while(sum-maxi > k){
                v[s[i]-'A']--;
                i++;
                maxi = *max_element(v.begin(),v.end()) ,
            sum = accumulate(v.begin(),v.end(),0);
            }
                ans = max(ans, j-i+1);
                j++;
            //  cout<<i<<" "<<sum<<" "<<maxi<<endl;
       }
       return ans;
    }
};
