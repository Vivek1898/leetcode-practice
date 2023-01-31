class Solution {
public:
 vector<string> ans;
    void dfs(map<string,multiset<string>>&mp,string s){
        
        while(!mp[s].empty()){
            string tp=*mp[s].begin();
            mp[s].erase(mp[s].find(tp));
            dfs(mp,tp);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string,multiset<string>> mp;
        
        for(auto x: tickets){
            mp[x[0]].insert(x[1]);
        }
        
        dfs(mp,"JFK");
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};