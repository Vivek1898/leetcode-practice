class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int killed=0;
        while(q.size()>1){
            int val=q.front();
            q.pop();
            killed++;
            if(killed==k){
                killed=0;
            }else{
                q.push(val);
            }
        }
        return q.front()+1;
        
    }
};