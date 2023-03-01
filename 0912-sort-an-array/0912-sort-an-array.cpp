class Comp {
    public:
    bool operator()(int a, int b) {
        return a >= b;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, Comp> pq;
        for (auto i:nums) pq.push(i);
        vector<int> ans;
        while (!pq.empty()) {
            ans.emplace_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};