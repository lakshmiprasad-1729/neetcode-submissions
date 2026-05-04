class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        multiset<int> ms;
        sort(v.begin(),v.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
          auto t = ms.lower_bound(v[i][1]);
          auto it = ms.upper_bound(v[i][0]);
          if(it != ms.end()){
             ans++;
             if(t!=ms.end()) ms.erase(t),ms.insert(v[i][1]);
          }
          else ms.insert(v[i][1]);
        }
        return ans;
    }
};
