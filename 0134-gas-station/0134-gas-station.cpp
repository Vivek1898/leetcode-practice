class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int netCost=0;
        int start=0;
        int curr=0;
        
        for(int i=0;i<gas.size();i++){
            netCost+=gas[i]-cost[i];
               netCost+=gas[i]-cost[i];
                  curr+=gas[i]-cost[i];
            if(curr<0){
                curr=0;
                start=i+1;
                
            }
        }
        
        if(netCost < 0) return -1;
        else return start;
    }
};