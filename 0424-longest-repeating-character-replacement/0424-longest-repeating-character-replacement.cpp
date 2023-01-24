class Solution {
public:
    int characterReplacement(string s, int k) {
        
        map<char,int>m;
        int slow=0;
        int repeat=0;
        int maxLen=0;
        
        for(int f=0;f<s.size();f++){
            char right=s[f];
            m[right]++;
            repeat=max(repeat, m[right]);
            
            
            while(f-slow+1-repeat > k){
                char left=s[slow];
                m[left]--;
                slow++;
            }
            
            
            maxLen=max(maxLen,f-slow+1);
            
        }
        return maxLen;
    }
};