class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> perm;
        if(s==""){
            return perm;
        }
        
        perm.push_back(s);
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                int n=perm.size();
                for(int j=0;j<n;j++){
                    vector<char>chars(perm[j].begin(),perm[j].end());
                    if(isupper(chars[i])){
                        chars[i]=tolower(chars[i]);
                    }else{
                         chars[i]=toupper(chars[i]);
                    }
                            perm.push_back(string(chars.begin(),chars.end()));

                }
            }
        }
        return perm;
    }
};