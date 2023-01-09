class Solution {
public:
    vector<string>res;
    void helper(int op,int co,int n,int cntr,string &ans){
        if(cntr==2*n){
            res.push_back(ans);
            return;
        }
        
        if(op<n){
            ans+="(";
            helper(op+1,co,n,cntr+1,ans);
             ans.pop_back();
            
        }
        if(co<op){
            ans+=")";
            helper(op,co+1,n,cntr+1,ans); 
            ans.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int op=0;
        int co=0;
        int cntr=0;
        string ans="";
        helper(op,co,n,cntr,ans);
        
        return res;
    }
};