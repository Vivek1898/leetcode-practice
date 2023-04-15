class Solution {
public:
int dp[1001][2001]; 
int solve(vector<vector<int>>& piles, int k,int i){
    if(i>=piles.size())
    return 0; 
    if(dp[i][k]!=-1)
    return dp[i][k]; 
    int x=0;
     x = max(x,solve(piles,k,i+1)); 
     for(int j=0;j<piles[i].size();j++){
         if(j+1<=k){
             x = max(x,piles[i][j]+solve(piles,k-j-1,i+1)); 
         }
         else {
             break; 
         }
     }
     return dp[i][k] =x; 
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size(); 
        for(int i=0;i<n;i++){
            int m= piles[i].size(); 
            for(int j=1;j<m;j++){
                piles[i][j] = piles[i][j] + piles[i][j-1]; 
            }
        }
       memset(dp,-1,sizeof(dp)); 
    
        return solve(piles,k,0); 
    }
};