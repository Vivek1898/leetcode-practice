class Solution {
public:
    int maxProfit2(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            int tmp = s0;
            s0 = max(s0, s1+p);
            s1 = max(s1, tmp-p-fee);
        }
        return s0;
    }
     int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        if (n < 2) return 0;
        vector<int> hold(n, 0), sold(n, 0);
        hold[0] = -p[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], sold[i - 1] - p[i]);
            sold[i] = max(sold[i - 1], hold[i - 1] - fee + p[i]);
        }

        return sold[n - 1];
    }
};