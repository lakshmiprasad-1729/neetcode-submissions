class Solution {
public:
    void solve(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& visited){
      int n = grid.size() , m = grid[0].size();
      if(i >= n || j >= m || i < 0 || j < 0) return ;
      if(grid[i][j]=='0' || visited[i][j]) return;
      visited[i][j] = true;
      solve(grid,i-1,j,visited) , solve(grid,i+1,j,visited),solve(grid,i,j-1,visited) ,
      solve(grid,i,j+1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m =grid[0].size();
         int ans = 0;
         vector<vector<bool>> visted(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            if(grid[i][j]=='0' || visted[i][j]) continue;
            ans++;
            solve(grid,i,j,visted);
          }
        }

        return ans;
    }
};
