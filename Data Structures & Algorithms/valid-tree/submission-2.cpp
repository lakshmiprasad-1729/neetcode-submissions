class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
       vector<vector<int>> v(n);
       int m = edges.size();
       for(int i = 0 ; i < m ; i++){
         if(edges[i][0]==edges[i][1]) return false;
         v[edges[i][0]].push_back(edges[i][1]);
         v[edges[i][1]].push_back(edges[i][0]);
       }
       vector<bool> visted(n,false);
       stack<int> stk;
       stk.push(0);
       while(!stk.empty()){
        int node = stk.top() ; stk.pop();
        if(visted[node]) return false;
        visted[node] = true;
        for(auto it: v[node]){
          if(!visted[it]) stk.push(it);
        }
       }

       for(int i = 0 ; i < n ; i++){
         if(!visted[i]) return false;
       }
       return true;
    }
};
