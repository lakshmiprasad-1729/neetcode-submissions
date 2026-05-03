class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int j = 0 ; j < n ; j++){
            int a = 0 , b = j , x = j , y = 0;
            while( a <= x){
                swap(v[a][b],v[x][y]);
                x--; y++; a++; b--;
            }
        }
        // cout<<"hello"<<endl;
        for(int i = 1 ; i < n ; i++){
            int a = n-1 , b = i , x = i , y = n-1;
            while( a >= x){
                swap(v[a][b],v[x][y]);
                a--; b++; x++; y--;
            }
        }

        for(int i = 0 ; i < n ; i++) reverse(v[i].begin(),v[i].end());
    }
};
