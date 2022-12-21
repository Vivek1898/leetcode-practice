class Solution {

    vector<vector<int>> graph;
    vector<int> col;
    vector<int> vis;

    bool dfs(int p){
        vis[p] = 1;
        for(auto v: graph[p]){
            if(!vis[v]){
                col[v] = 1 - col[p];
                if(!dfs(v))
                    return false;
            }else if(col[v] == col[p]) 
                return false;
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vis.resize(n+1, 0);
        col.resize(n+1, -1);
        graph.resize(n+1);
        for(auto d: dis){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        for(int i=1; i<=n; i++){
            if(col[i] == -1){
                col[i] = 1;
                if(!dfs(i))
                    return false;
            }
        }
        return true;
    }
};