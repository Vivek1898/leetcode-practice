class Solution {
public:
int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=1) return 0;
        queue<int> q;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) mpp[arr[i]].push_back(i);

        q.push(0);
        int step = 0;

        while (q.size()) {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int j = q.front(); q.pop();

                if (j - 1 >= 0 && mpp.find(arr[j - 1]) != mpp.end()) q.push(j - 1);
                if (j + 1 < n && mpp.find(arr[j + 1]) != mpp.end()) {
                    if (j + 1 == n - 1) return step;
                    q.push(j + 1);
                }

                if (mpp.find(arr[j]) != mpp.end()) {
                    for (auto nbr : mpp[arr[j]]) {
                        if (nbr == j) continue;
                        if (nbr == n - 1) return step;
                        q.push(nbr);
                    }
                }
                mpp.erase(arr[j]);
            }
        }
        return step;
    }
};