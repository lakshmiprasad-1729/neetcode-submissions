class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int num;
        vector<int> dp(102,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++) 
              if(matrix[i][j] < 101 && matrix[i][j] > 0) dp[matrix[i][j]]=1;
        }

        for(int i = 1 ; i < 102 ; i++)
           if(dp[i]==0){
            num =i; break;
           }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]==0){
                    for(int  k = 0 ; k < n ; k++) if(matrix[k][j] != 0) matrix[k][j]=num;
                    for(int k = 0 ; k < m ; k++) if(matrix[i][k] != 0) matrix[i][k] = num;
                }
            }
        }

        for(int i = 0 ; i < n ; i++)
          for(int j = 0 ; j < m ; j++)
            if(matrix[i][j]==num) matrix[i][j] = 0;

        // return ans;
    }
};
