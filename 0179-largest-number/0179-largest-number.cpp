class Solution {
public:
static bool cmp(string &a,string &b){

        return (a+b)>(b+a);
    
}
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto &i:nums){
            v.push_back(to_string(i));
        }
        string ans="";
        bool flag=true;
        sort(v.begin(),v.end(),cmp);
        for(auto &i:v){
            ans+=i;
             // if all the integers are 0, the ans should return a single "0"
        if(i != "0") flag = false;    
        }
        
        if(flag) return "0";
        else return ans;
    }
};