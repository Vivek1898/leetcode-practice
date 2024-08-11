class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int total = 0; // Total oranges
        int rotten = 0; // Rotting oranges after the process
        int minutes = 0; // Minutes taken for all oranges to rot
        
        int rs = grid.size();
        int cs = grid[0].size();
        queue<pair<int, int>> q;
        
        // Count total oranges and push all initially rotten oranges into the queue
        for (int i = 0; i < rs; i++) {
            for (int j = 0; j < cs; j++) {
                if (grid[i][j]) total++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        
        // Perform BFS from each rotten orange
        while (!q.empty()) {
            int size = q.size();
            rotten += size; // Increase count of rotten oranges
            
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                // Check all 4 possible directions
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    // If it's a valid cell and the orange is fresh, rot it
                    if (nx >= 0 && ny >= 0 && nx < rs && ny < cs && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            
            // Increment minutes if the queue is not empty
            if (!q.empty()) minutes++;
        }
        
        // If all oranges have rotted, return the time taken, otherwise return -1
        return (rotten == total) ? minutes : -1;
    }
};
