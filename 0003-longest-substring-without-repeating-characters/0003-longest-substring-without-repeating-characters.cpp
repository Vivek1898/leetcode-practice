class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int slow=0;
        int maxLen=0;
        for(int f=0;f<s.size();++f){
            int r=s[f];
            if(mp.find(r)!=mp.end()){
                slow=max(slow,mp[r]+1);
            }
            mp[r]=f;
            maxLen=max(maxLen,f-slow+1);
        }
        return maxLen;
    }
};