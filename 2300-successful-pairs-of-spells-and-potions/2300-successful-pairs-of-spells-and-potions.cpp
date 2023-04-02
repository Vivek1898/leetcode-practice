class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(long s: spells){
            int idx = potions.size();
            long l = 0, r = potions.size() - 1;
            while(l <= r){
                int m = ((r - l) / 2) + l;
                if(s * potions[m] >= success){
                    r = m - 1;
                    idx = m;
                }
                else{
                    l = m + 1;
                }
            }
            res.push_back(potions.size() - idx);
        }
        return res;
    }
};
