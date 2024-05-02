#include <unordered_map>

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> countMap;
        
       
        for (int num : nums) {
            countMap[num]++;
        }
        
        int maxK = -1;
   
        for (const auto& kvp : countMap) {
            int k = kvp.first;
            
            // Check if -k exists in the map and update maxK 
            if (k > 0 && countMap.count(-k) > 0) {
                maxK = max(maxK, k);
            }
        }
        
        return maxK;
    }
};
