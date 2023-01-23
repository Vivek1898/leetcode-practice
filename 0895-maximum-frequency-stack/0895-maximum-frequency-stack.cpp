class FreqStack {
public:
    int pos = 1;
    priority_queue<vector<int>> pq;
    unordered_map<int,int> mp;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;  
        pq.push({mp[val],pos++,val});
    }
    
    int pop() {
        auto curr = pq.top();
       // cout<<curr[2]<<endl;
        pq.pop();
        mp[curr[2]]--;  //decreasing the frequency of current element in map
        return curr[2];
    }
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */