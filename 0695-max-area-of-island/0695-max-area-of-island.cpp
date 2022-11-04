class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i, int j, int& area){
       if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()  || grid[i][j] == 0) return;
        //Mark visited
        grid[i][j]=0;
        area+=1;
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
        
     

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
          int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int area=0;
                if(grid[i][j]==1){
                dfs(grid,i,j,area);
                maxArea=max(area,maxArea);
            }
            
            }
        }
        return maxArea;
    }
};