class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        stack<pair<int,int>> ascend,descend;

        // combine profit,capital for sorting based on profit
        for(int i=0;i<profits.size();i++)
            v.push_back(make_pair(profits[i],capital[i]));
        sort(v.begin(), v.end());

        // push all values to ascend,were value of top = highest profit
        for(auto a:v)
            ascend.push(a);

        while(k && !ascend.empty()) {
            if(w >= ascend.top().second) {
                w += ascend.top().first;
                ascend.pop();
                while(!descend.empty()) {
                    ascend.push(descend.top());
                    descend.pop();
                }
                k--;
            } else {
                descend.push(ascend.top());
                ascend.pop();
            }
        }
        return w;
    }
};