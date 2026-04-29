class Solution {
public:
bool ans = true;
  void dfs(vector<vector<int>>& adj,vector<bool> &visted,int node){
    visted[node]=true;
    for(auto it: adj[node]){
        if(visted[it]){
          ans &= false; return;
        }
      dfs(adj,visted,it);
    }
    visted[node]=false;
  }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        int n = pre.size();
        for(int i = 0 ; i < n ; i++){
          adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<bool> visted(num);
       for(int i = 0 ; i < num ; i++){
           dfs(adj,visted,i);
       }
        return ans;
    }
};
