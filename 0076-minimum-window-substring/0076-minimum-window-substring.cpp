class Solution {
public:
    string minWindow(string s, string t) {
        int slow=0;
        int minlen=INT_MAX;
        int cnt=0;
        int minstart=0;
       unordered_map<char,int>mp;
        
        for(auto it:t)mp[it]++;
        
        for(int fast=0;fast<s.size();fast++){
            if(mp[s[fast]]>0) cnt++;
            mp[s[fast]]--;
          
            
            if(cnt==t.length()){
                
            while(slow<fast and  mp[s[slow]]<0){
                mp[s[slow]]++;
                slow++;
            }
                if(minlen>fast-slow+1){
                    minstart=slow;
                    minlen=fast-slow+1;
                }
            }
        }
        
        if(minlen==INT_MAX) return "";
        return s.substr(minstart,minlen);
    }
};