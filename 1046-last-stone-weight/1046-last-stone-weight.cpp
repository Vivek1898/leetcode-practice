class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>>pq;
        
        for(auto it:stones ){
            pq.push(it);
        }
        int f,s;
        
        while(pq.size()!=1){
            f=pq.top();
            cout<<f<<endl;
            pq.pop();
            s=pq.top();
            cout<<s;
            pq.pop();
            pq.push(f-s);
        }
        
        
        return pq.top();
    }
};