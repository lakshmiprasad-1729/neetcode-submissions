class Solution {
public:
    void dfs(vector<int>& ans,vector<vector<int>>& v,int i1 , int i2 ,int j1 , int j2){
        if( i1 > i2 || j1 > j2) return;
        if(i1==i2 && j1 == j2){
            ans.push_back(v[i1][j1]);
            return;
        }
        for(int k = j1 ; k < j2 ; k++) ans.push_back(v[i1][k]);
        for(int k = i1 ; k< i2 ; k++) ans.push_back(v[k][j2]);
        for(int k = j2 ; k > j1 ; k--) ans.push_back(v[i2][k]);
        for(int k = i2 ; k > i1 ; k--) ans.push_back(v[k][j1]);
        dfs(ans,v,i1+1,i2-1,j1+1,j2-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        dfs(ans,matrix,0,(int)matrix.size()-1,0,(int)matrix[0].size()-1);
        int n = matrix.size() , m = matrix[0].size();
        while((int)ans.size() > (n*m)) ans.pop_back();
        return ans;
    }
};
