class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
          unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:m){
            q.push(it.second);
        }

        while(k>0){
            k-=q.top();
            if(k>=0){
                q.pop();
            }
        }
        return q.size();
    }
};