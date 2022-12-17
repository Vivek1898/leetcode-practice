class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerset;
        powerset.push_back({});
        for(auto currentNumber:nums){
            int n=powerset.size();
            for(int i=0;i<n;i++){
                // duplicates + new
                  vector<int>copy(powerset[i]);
                    copy.push_back(currentNumber);
                        powerset.push_back(copy);
            }
            
        }
        return powerset;
        
    }
};