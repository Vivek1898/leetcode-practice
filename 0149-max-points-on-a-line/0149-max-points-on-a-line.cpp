class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxpoints = 0;
       
        for(int i=0;i<points.size();i++){
             unordered_map<float,int> mp;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]-points[j][0] !=0){
                float ans = (float (points[j][1] - points[i][1]) /float (points[j][0] - points[i][0]));
                mp[ans]++;
                if(mp[ans]>maxpoints)
                maxpoints = mp[ans];
            }
            else{
                mp[INT_MAX]++;;
                 if(mp[INT_MAX]>maxpoints)
                maxpoints = mp[INT_MAX];
            }
        }
        }
        return maxpoints+1;
    }
};
