class Solution {
public:
   // bool dfs(vector<int> adjList[graph.size()+1];)
    
     bool dfs(vector<vector<int>>& graph,vector<int>&vis,int pc,int node) {
      
        if(vis[node]!=0) return  vis[node]!=pc;
        vis[node]=-1*pc;
        
        for(auto ch:graph[node]){
            if(!dfs(graph,vis,vis[node],ch))
                return false;
        }
        return true;
        
        
    }
       
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>vis(graph.size(),0);
        
       
        
        for(int i=0;i<graph.size();i++){
               if(vis[i] == 0 and !dfs(graph,vis,-1,i)) return false;
        }
        return true;
     
        
    }
};