class Solution {
public:
   string reorganizeString(string s) {
        int n = s.size();
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        string ans;
        
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        
        for (auto c: m) {
            pq.push({c.second, c.first});
        }
        
        while(pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            
            auto b = pq.top();
            pq.pop();
            
            ans += a.second;
            ans += b.second;
            
            a.first -= 1;
            b.first -= 1;
            
            if (a.first > 0) {
                pq.push(a);
            }
            
            if (b.first > 0) {
                pq.push(b);
            } 
        }
        
        if (pq.size() > 0) {
            if (pq.top().first > 1) {
                return "";
            } else {
                ans += pq.top().second;
            }
        }
        
        return ans;
    }
};