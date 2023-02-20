class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int ans=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        
        if(k!=0){
            
            
            for(auto it:mp){
                if(mp.find(it.first+k)!=mp.end()) ans++;
            }
        }else{
            
            for(auto it:mp){
                if(it.second>1) ans++;
            }
        }
        
        
        return ans;
        
    }
};