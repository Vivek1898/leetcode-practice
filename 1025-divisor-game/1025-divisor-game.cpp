class Solution {
public:
    bool divisorGame(int n) {
        res = !res;
        for(int i=1; i<n; ++i)
        {
            if(n % i == 0)
            {
                return divisorGame(n-i);
            }
        }
        return res;
    }
private:
    bool res = true;
};