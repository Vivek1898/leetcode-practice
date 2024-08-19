class Solution {
    private:
    bool kokoCan(vector<int>& piles,int speed,int h){
        long goodHr=0;
        for(auto currBanana:piles){
            int currSpd=currBanana/speed;
            goodHr+=currSpd;
            if(currBanana%speed!=0) goodHr++;
        }
        return goodHr<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        int ans=-1;
        while(low<=high){
            int midSpeed = low+(high-low)/2;
            
            if(kokoCan(piles,midSpeed,h)){
                ans=midSpeed;
                high=midSpeed-1;
            } 
            else low=midSpeed+1;
            
        }
        return ans;
    }
};