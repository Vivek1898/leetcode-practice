class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = n * (1 << (m - 1));
        for (int j = 1; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += (grid[i][0] == 1) ? grid[i][j] : 1 - grid[i][j];
            cnt = max(cnt, n - cnt);
            res += cnt * (1 << (m - 1 - j));
        }
        return res;
    }
};