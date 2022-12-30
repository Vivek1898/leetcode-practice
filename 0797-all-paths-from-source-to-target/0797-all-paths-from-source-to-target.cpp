class SolutionDFS {
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

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            auto topElement=q.front();
            q.pop();
            for(auto i:graph[topElement.back()]){
                topElement.push_back(i);
                if(i==graph.size()-1)
                    ans.push_back(topElement);
                else{
                    q.push(topElement);
                }
                topElement.pop_back();
            }
        }
        return ans;
    }
};