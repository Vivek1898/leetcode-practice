class Solution {
public:
    static bool cmp(string a,string b){
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums){
            v.push_back(to_string(i));
        }
        
        sort(v.begin(),v.end(),cmp);
       string  ans="";
        int cnt=0;
        for(auto i:v){
            if(i=="0") cnt++;
        }
        for(auto i:v){
            ans+=i;
            
            
            
        }
        
        return  cnt==v.size()?"0":ans;
        
    }
};