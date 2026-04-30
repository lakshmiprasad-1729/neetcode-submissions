class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int> s;
        vector<bool> visted(n,false);
        vector<vector<int>> v(n);
        for(int i = 0; i < (int)edges.size() ; i++){
          v[edges[i][0]].push_back(edges[i][1]);
          v[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0 ; i < n ; i++) s.insert(i);
         stack<int> stk;
         int ans = 0;
        while(!s.empty()){
          stk.push(*s.begin());
             ans++;
           while(!stk.empty()){
             int node = stk.top(); stk.pop();
             if(visted[node]) continue;
             s.erase(node);
             visted[node]=true;
             for(auto it:v[node]){
              if(!visted[it]) stk.push(it);
             }
           }
        }
        return ans;
    }
};
