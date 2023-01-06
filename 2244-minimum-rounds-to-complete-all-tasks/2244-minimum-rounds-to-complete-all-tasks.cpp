class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int ,int> count;
        int res=0;
        for(auto& task: tasks) count[task]++;
        for(auto& [k,v]:count){
            if(v==1)return -1;
            res+=(v+2)/3;
        }
        return res;
    }
};