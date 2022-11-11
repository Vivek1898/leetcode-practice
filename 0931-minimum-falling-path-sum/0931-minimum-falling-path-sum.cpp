class Solution {
public:
    int minPathL(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size())
            return 1e9;
        
        if(i==0)
            return matrix[0][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int d = matrix[i][j] + minPathL(i-1,j,matrix,dp);
        int ld = matrix[i][j] + minPathL(i-1,j-1,matrix,dp);
        int rd= matrix[i][j] + minPathL(i-1,j+1,matrix,dp);
        
        return dp[i][j] = min(d,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
		
		vector<vector<int>> dp(n,vector<int>(m,-1));
        

         for(int i=0;i<m;i++){
           mini=min(mini,minPathL(n-1,i,matrix,dp))  ;
         }
                
        return mini;
    }
};