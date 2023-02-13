class Solution2 {
public:
    int maxAreaBrute(vector<int>& height) {
        
    int ans=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int area=min(height[i],height[j])*(j-i);
                
                ans=max(area,ans);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int maxArea(vector<int>& height) {
        
    int ans=0;
        
        int low=0;
        int high=height.size()-1;
        while(low<high){
              int area=min(height[low],height[high]) * (high-low);
            ans=max(ans,area);
            if(height[low]<=height[high]){
                low++;
            }else{
                high--;
            }
           
        }
        
        
        return ans;
    }
};