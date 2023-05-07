class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int n=s.length();
        for(int i=0; i<n; i++) {
            m[s[i]]++;
        }
        int ans=0,flag=0;
        for(auto i:m) {
            if(!flag and i.second&1) {
                flag=1;
                ans++;
            }
            ans += (i.second/2) * 2;
        }
        return ans;
    }
};