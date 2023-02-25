class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (const int& num : nums) {
            if (num % 2 != 0) s.insert(num * 2);  else  s.insert(num); 
        }
        int min_dev = *(--s.end()) - *s.begin();
        while (*(--s.end()) % 2 == 0) {
            s.insert(*(--s.end()) / 2);
            s.erase(*(--s.end()));
            if (*(--s.end()) - *s.begin() < min_dev) 
            { 
                min_dev = *(--s.end()) - *s.begin(); 
            }
        }
        
    return min_dev;    
    }
};