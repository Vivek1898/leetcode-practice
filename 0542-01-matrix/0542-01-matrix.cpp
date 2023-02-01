class Solution {
public:
    
    bool isValid(int i, int j,int n,int m){
    return i >=0 && j >=0 && i < m && j < n;
}

    
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
	
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));

        queue<pair<int,int>> q;
        
		// distance of 0 from nearest 0 will be 0 (itselff)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
		// right, bottom, left, top - directions in which we can move
        vector<pair<int,int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
			// position of element whose result is known
            int curx = cur.first;
            int cury = cur.second;
            
			// traversing in all possible direction
            for(auto dir: dirs){
                int x = curx + dir.first;
                int y = cury + dir.second;
                
                if(isValid(x,y,n,m)) {
                
                if(dist[x][y]>dist[curx][cury]){
                    dist[x][y]=dist[curx][cury]+1;
                    q.push({x,y});
                }
                
                }

        }
        
        }
        return dist;
    }
};