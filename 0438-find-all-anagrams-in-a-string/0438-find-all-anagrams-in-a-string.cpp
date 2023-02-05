class Solution {
public:
    bool isMatching(vector<int> &a, vector<int> &b){
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return 0;
        }
        
        return 1;
    }

    vector<int> findAnagrams(string s, string p) {
        
        if(p.size() > s.size()) return {};
        int slow=0;
        int match=0;
        // unordered_map<char,int>m;
        vector<int> fre(26, 0);
        for(auto chr:p){
            fre[chr - 'a']++;
        }
        
        vector<int> curr(26, 0);
        for(int i = 0; i < p.size(); i++){
            curr[s[i] - 'a']++;
        }
        
        vector<int>idx;
        if(isMatching(fre, curr)) 
            idx.push_back(0);
        
        for(int i = p.size(); i < s.size(); i++){
            curr[s[i] - 'a']++;
            curr[s[i - p.size()] - 'a']--;
            
            if(isMatching(fre, curr)) idx.push_back(i - p.size() + 1);
        }
        

        return idx;
    }
};