class Solution {
public:
    int sumCount(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
       if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j]+ sumCount(i-1,j,matrix,dp);
          int left = matrix[i][j]+ sumCount(i,j-1,matrix,dp);
        return dp[i][j]=min(up,left);
        
    }

        
    int minPathSumMemo(vector<vector<int>>& grid) {
        int n=grid.size();
         int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
    return sumCount(n-1,m-1,grid,dp);
    }
    
      int minPathSumDP(vector<vector<int>>& grid) {

                  int n=grid.size();
         int m=grid[0].size();
      vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    }
    
    
       int minPathSum(vector<vector<int>>& grid) {

                  int n=grid.size();
         int m=grid[0].size();
      vector<int > prevRow(m,0);
    for(int i=0; i<n ; i++){
        vector<int> currRow(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) currRow[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prevRow[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=currRow[j-1];
                else left += 1e9;
                
                currRow[j] = min(up,left);
            }
        }
        prevRow=currRow;
    }
    
    return prevRow[m-1];
    }
};