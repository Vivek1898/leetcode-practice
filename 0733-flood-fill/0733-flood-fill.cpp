class Solution {
public:
    int delRow[4] = {-1, 0, +1, 0};  // Up, Right, Down, Left
    int delCol[4] = {0, +1, 0, -1};  // Up, Right, Down, Left
    
    void dfs(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& image, int initialColor, int color) {
        // Color the current pixel
        ans[r][c] = color;

        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int dx = r + delRow[i];
            int dy = c + delCol[i];

            // Check if the new position is within bounds and has the initial color
            if (dx >= 0 && dx < image.size() && dy >= 0 && dy < image[0].size() && image[dx][dy] == initialColor && ans[dx][dy] != color) {
                dfs(dx, dy, ans, image, initialColor, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        // If the starting pixel already has the target color, return the image as is
        if (initialColor != color) {
            dfs(sr, sc, ans, image, initialColor, color);
        }

        return ans;
    }
};
