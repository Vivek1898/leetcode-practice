class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& currAns,int curr){
        currAns.push_back(curr);
        if(curr==graph.size()-1)ans.push_back(currAns);
        else{
            for(int i:graph[curr]){
                dfs(graph,ans,currAns,i);
            }
        }
        currAns.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> currAns;
        dfs(graph,ans,currAns,0);
        return ans;
    }
};