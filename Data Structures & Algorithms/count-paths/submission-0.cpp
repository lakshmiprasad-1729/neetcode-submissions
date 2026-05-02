class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<int> prev(n,0) , curr(n,0);
      for(int i = m-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i==m-1 && j == n-1){
                curr[j] = 1; continue;
            }

            if(j+1 < n) curr[j] +=curr[j+1];
            if(i+1 < m) curr[j] +=prev[j];
        }
        for(int j = 0 ; j < n ; j++) prev[j] = curr[j] , curr[j] =0;
      }   
      return prev[0];
    }
};
