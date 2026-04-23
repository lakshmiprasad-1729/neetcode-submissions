class Solution {
public:
    bool check(vector<int>& a,vector<int>& b,string t){
        int n = t.length();
        for(int i = 0 ; i < n ; i++){
            if(a[t[i]] > b[t[i]]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length() , m = t.length();
        vector<int> a(130,0),b(130,0);
        for(int i = 0 ; i < m ; i++) a[t[i]]++;
        int i = 0 , j = 0;
        int l = 0 , r = 1e4;
        while(j < n){
            b[s[j]]++;
            while(check(a,b,t)){
               if((j-i+1)<(r-l+1)) l = i , r = j;
               b[s[i]]--;
               i++;
            }
            // cout<<i<<endl;
            j++;
        }
          
        if(r==1e4) return "";
        string ans = "";
        for(int i =  l ; i <= r ; i++){
           ans+=s[i];
        }
        return ans;
    }
};
