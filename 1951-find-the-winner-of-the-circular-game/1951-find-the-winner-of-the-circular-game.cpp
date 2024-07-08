class Solution3 {
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


class Solution2 {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};


class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for converting 0-based indexing to 1-based indexing
    }
};