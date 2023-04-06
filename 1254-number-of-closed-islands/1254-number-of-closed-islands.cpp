class Solution {
public:
    vector<vector<int>> grid;
    int m,n;
    int isVisited[101][101] = {false};

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValidIndex(int x, int y) {
        return x>=0 && y>=0 && x<m && y<n;
    }

    bool isEdgeIndex(int x, int y) {
        return x==0 || y==0 || x==m-1 || y==n-1;
    }

    void dfs(int x, int y) {
        if(isVisited[x][y]) return;
        isVisited[x][y] = true;

        if(grid[x][y] != 0) return;

        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValidIndex(nx,ny) && !isVisited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        //Visit all lands that are connected to the edge
        //Invalid lands
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isEdgeIndex(i,j)) {
                    if(grid[i][j]==0 && !isVisited[i][j]) {
                        dfs(i,j);
                    }
                }
            }
        }

        //Now find the VALID lands.
        int component = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0 && !isVisited[i][j]) {
                    dfs(i,j);
                    component++;
                }
            }
        }
        return component;
    }
};