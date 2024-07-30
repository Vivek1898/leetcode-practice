class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(auto i:strs){
            
            string word=i;
            sort(i.begin(),i.end());
            m[i].push_back(word);
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};