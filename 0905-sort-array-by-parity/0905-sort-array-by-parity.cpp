class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
    
    int   n=a.size();
        vector<int>ans;
        for(auto i:a){
            if(i%2==0) 
            {
                ans.push_back(i);
            } 
    }
             for(auto i:a){
            if(i%2!=0) 
            {
                ans.push_back(i);
            } 
    }
        return ans;
    }
};