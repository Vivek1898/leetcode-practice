class Solution {
public:
    double average(vector<int>& s) {
        
        sort(s.begin(),s.end());
        
        vector<int>::iterator it,it2;
 
    it = s.begin();
    s.erase(it);
        s.pop_back();
        
        double sum =accumulate(s.begin(),s.end(),0);
        return sum/s.size();
        
        
    }
};