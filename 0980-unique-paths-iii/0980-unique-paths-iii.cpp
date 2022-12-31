class Solution {
public:
   //we will increment cnt only if we have travelled all the zero cells available to us!
     int cnt=0;
    void paths(int i,int j,vector<vector<int>>& g,int n,int m,vector<vector<bool>>&vis,int zero)
    {
        //check if we go out of bounds or we land on blocked cell
        if(i<0||j<0||i>=n||j>=m||vis[i][j]||g[i][j]==-1)
           return;
        //if we reach the target cell
        if(g[i][j]==2)
        {
            //we would have made zero ==-1 because landing on 2 would also have done -1 to zero as at 2 we came from last zero cell hence we will have zero==-1
            if(zero==-1)
            cnt++;
            return;
        }
        //mark the current cell as visited
        vis[i][j]=true;
        
        //go down
        paths(i+1,j,g,n,m,vis,zero-1);
        //go up
        paths(i-1,j,g,n,m,vis,zero-1);
        //go right
        paths(i,j+1,g,n,m,vis,zero-1);
        //go left
        paths(i,j-1,g,n,m,vis,zero-1);
        //backtrack
        vis[i][j]=false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        //this will store the visited cell
         vector<vector<bool>>vis(n,vector<bool>(m,false));
        int si=0,sj=0,zero=0;
        for(int i=0;i<n;i++)
        {  
            for(int j=0;j<m;j++)
            {
              if(grid[i][j]==1)
              {
                  //store the indexes of the starting cell
                  si=i;
                  sj=j;
              }
                //side by side count the number of zero cells available
                else if(grid[i][j]==0)
                    zero++;
            }
        }
        
        paths(si,sj,grid,n,m,vis,zero);
        return cnt;
    }
};