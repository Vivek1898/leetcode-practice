class Solution {
public:
  bool detectCycle(vector<int> &edges,vector<int>&vis,vector<int>&recStack,int src,
       int& counter,int &timer){
       if(edges[src]==-1) return false;
        vis[src]=1;
        recStack[src]=timer;
        timer++;
        int adjNode=edges[src];
            if(!vis[adjNode] && detectCycle(edges,vis,recStack,adjNode,counter
            ,timer)==true){
                recStack[adjNode]=0;
                return true;
            }

               else if(recStack[adjNode]!=0){
                   counter=timer-recStack[adjNode];
                   recStack[adjNode]=0;
                   return true;
               }

        recStack[src]=0;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        int nodes=edges.size(),res=-1;
        vector<int>recStack(nodes,0);
        vector<int> vis(nodes,0);

        for(int i=0;i<nodes;i++){
            if(vis[i]==0) {
                int counter=-1;
                int timer=1;
                bool isCycle=detectCycle(edges,vis,recStack,i,counter,timer);
                if(isCycle==true)
                res=max(res,counter);
            }
        }
        return res;
    }
};