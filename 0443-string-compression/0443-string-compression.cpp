class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int n= chars.size();
        int i=0, j=0;
        vector<pair<char, int>>v;
        while(j<n){
            if(chars[i]==chars[j]) j++;
            else{
                v.push_back({chars[i], j-i});
                i=j; j++;
            }
        }
        v.push_back({chars[i], j-i});
        for(auto value: v) {
            if(value.second==1) s+=value.first;
            else{
                s+=value.first;
                string a= to_string(value.second);
                s+=a;
            }
        }
        for(int i=0; i<s.size();i++){
            chars[i]=s[i];
        }
       // for(auto value: chars) cout<<value;
        return s.size();
        
    }
};