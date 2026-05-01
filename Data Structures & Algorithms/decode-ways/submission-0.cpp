class Solution {
public:
    int numDecodings(string s) {
      int n = s.length();
      vector<int> v(n+1,0);
      v[0]=1;
      if(s[0]!='0') v[1]=1;

      for(int i = 1 ; i < n ; i++){
        if(s[i] != '0') v[i+1]+=v[i];
        const char ch[] = {s[i-1],s[i]};
        int num  = stoi(ch);
        if(num <= 26 && s[i-1] != '0') v[i+1]+=v[i-1];
      }
      return v[n];
    }
};
