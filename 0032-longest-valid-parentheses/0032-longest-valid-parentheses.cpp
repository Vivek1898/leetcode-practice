class Solution {
    int lonParen(int i, string & s, vector<int> & memo){
        if(i <= 0){
            return 0;
        }
        
        if(memo[i] != -1){
            return memo[i];
        }
        
        if(s[i] == '('){
            memo[i] = 0;
        }
        else if(s[i] == ')' && s[i - 1] == '('){
            memo[i] = lonParen(i - 2, s, memo) + 2;
        }
        else if(s[i] == ')' && s[i - 1] == ')'){
            int len = lonParen(i - 1, s, memo);
            if(i - 1 - len >= 0 && s[i - 1 - len] == '('){
                memo[i] = len + 2 + lonParen(i - len - 2, s, memo);
            }
            else{
                memo[i] = 0;
            }
        }
        return memo[i];
    }
public:
    int longestValidParentheses(string s) {
        
        int n = s.size(), maxLen = 0;
        vector<int> memo(n, -1);
        for(int i = 0; i < n; i++){
            maxLen = max(maxLen, lonParen(i, s, memo));
        }
        return maxLen;
    }
};