class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                word.push_back(temp);
                temp = "";
            }   
            else temp.push_back(s[i]);
        }
        word.push_back(temp);   
        if(pattern.size() != word.size()) return false;
        unordered_map<char, string> mp;
        for(int i = 0; i < pattern.size(); i++){
            if(mp.find(pattern[i]) == mp.end()){
                mp[pattern[i]] = word[i];
            }
            else if(mp[pattern[i]] != word[i]) return false;
        }
        unordered_set<string> set;
        for(auto it : mp){
            set.insert(it.second);
        }
        if(mp.size() != set.size()) return false; 
        return true;    
    }
};