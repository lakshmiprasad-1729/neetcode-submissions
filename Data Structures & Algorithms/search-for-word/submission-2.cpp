class Solution {
public:
    bool solve(vector<vector<char>>& board,string word,int i,int r,int c){
      int n = board.size() , m = board[0].size();
      
      int len = word.length();

      if(i >= len) return true;

      if( r >= n || r < 0 || c >= m || c < 0) return false;

      if(board[r][c] != word[i]) return false;

      char temp = board[r][c]; board[r][c] ='!';

      bool ans = false;
      ans = ans | solve(board,word,i+1,r-1,c) | solve(board,word,i+1,r+1,c) |
             solve(board,word,i+1,r,c-1) | solve(board,word,i+1,r,c+1);
      board[r][c] = temp;
      
      return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
       bool ans = false;

       int n = board.size() , m = board[0].size();
    
       for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){
           ans |= solve(board,word,0,i,j);

           if(ans) return ans;
         }
       }
       return false;
    }
};
