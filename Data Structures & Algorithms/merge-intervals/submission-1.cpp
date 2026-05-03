class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
         int n = v.size();
         vector<vector<int>> ans; sort(v.begin(),v.end());
         int c = v[0][0] , d = v[0][1];
         for(int i = 1 ; i < n ; i++){
            int t1 = v[i][0] , t2 = v[i][1];
            if(t1 <= d && t2 >=c){
                c = min(c,t1) , d = max(d,t2);
                // cout<<t1<<" "<<d<<endl;
            }
            else{
                if(c < t1) ans.push_back({c,d}) , c = t1 , d = t2;
                else ans.push_back({t1,t2});
            }
         }
         ans.push_back({c,d});
         return ans;
    }
};
