class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        sort(p.begin(),p.end());
        int low=0;
        int high=p.size()-1;
        int count=0;
        while(low<=high){
            int sum=p[low]+p[high];
            
            if(sum<=limit){
                low++;
                high--;
                
            }else{
                high--;
            }
            count++;
            
        }
        return count;
    }
};