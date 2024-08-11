class Solution {
public:
    void dfs(vector<vector<int>>& adj, int idx, vector<bool>& vis) {
        vis[idx] = true;
        for (int i = 0; i < adj[idx].size(); i++) {
            if (adj[idx][i] == 1 && !vis[i]) {
                dfs(adj, i, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        vector<bool> vis(sz, false);
        int cnt = 0;

        for (int i = 0; i < sz; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(isConnected, i, vis);
            }
        }

        return cnt;
    }
};
