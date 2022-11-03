class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          map<char,int> m;
        
        int ans=0;
        
        for(int ahead=0,back=0;ahead<s.size();){
            if(!m[s[ahead]]){
                m[s[ahead]]++;
                ahead++;
                ans=max(ans,ahead-back);
            }
            else{
                m[s[back]]--;
                back++;
            }
        }
        return ans;
    }
};