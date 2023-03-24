class Solution {
private:
    bool search(unordered_map<string, int> mp,string s, int start, int m,int n ){
        int i = start;
        int time = 0;
        for(; i < s.length() && time < m;i+=n ){
            time++;
            string w = s.substr(i, n);
            if(mp[w] > 0){
                mp[w]--;  
            }else 
              return false;
        }
        for(auto [w , f]: mp){
            if(f != 0) return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size(); // words.length
        int n = words[0].size(); // words[i].length
        vector<int> ans;
        if(m * n > s.length()) return {};
        unordered_map<string, int> mp;
        for(auto w: words){
            mp[w]++;
        }
        int count = 0;
        for(int i = 0; i <= s.length() - m * n;i++){
            if(search(mp, s, i, m, n))
                ans.push_back(i);
        }
        return ans;
        
    }
};