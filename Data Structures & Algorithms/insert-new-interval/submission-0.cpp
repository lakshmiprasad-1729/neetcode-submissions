class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
       int n = a.size();
       vector<vector<int>> ans;
       vector<vector<int>> temp;  int c = b[0] , d = b[1];
       for(int i = 0 ; i < n ; i++){
          int t1 = a[i][0] , t2 = a[i][1];

          if(t1 <= d && t2 >= c){
            c = min(t1,c) , d = max(t2,d);
          }
          else{
            temp = {{t1,t2},{c,d}}; sort(temp.begin(),temp.end());
            ans.push_back(temp[0]);
            c = temp[1][0] , d = temp[1][1];
          }
       }
       ans.push_back({c,d});
       return ans;
    }
};
