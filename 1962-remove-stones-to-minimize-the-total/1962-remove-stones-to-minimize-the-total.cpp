class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin(),piles.end(),0);
        priority_queue<int> pq;
        for(auto it:piles)
        {
            pq.push(it);
        }
        while(k--)
        {
            int tp = pq.top();
            pq.pop();
            int val = floor(tp/2);
            pq.push(tp-val);
            sum -= val;
        }
        return sum;
    }
};