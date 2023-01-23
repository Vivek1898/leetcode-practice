#define pii pair<int,int>
class Solution {
    
    int distance(int x){
        return x*x;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int,pii>> pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int d= distance(x)+distance(y);
            pq.push(make_pair(d,make_pair(x,y)));
            if(pq.size()>k){
                pq.pop();
            }
        }
        
         vector<vector<int>> res;
        while(pq.empty()==false){
            auto it=pq.top();
            pq.pop();
            res.push_back(vector<int> {it.second.first,it.second.second});
        }
        return res;
    }
};