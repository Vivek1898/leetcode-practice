class Solution {
public:
  int cnt;
void dfs(vector<bool> &vis, int node, vector<vector<int>>&rooms){
        vis[node] = true ;
        cnt += 1 ;
        for(int it : rooms[node])
            if(!vis[it])
                dfs(vis, it, rooms) ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        vector<bool> vis(n,false) ;
        cnt =0 ;
        dfs(vis, 0, rooms) ;
        return cnt == n ;
    }
    
    };