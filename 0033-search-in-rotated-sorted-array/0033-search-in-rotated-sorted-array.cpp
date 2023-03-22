class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
// firstly we have to find pivot using binary search.
// then we have to check whether target is less or greater than pivot.
// if target is greater than pivot apply search on right half else left half. [4,5,6,7,8]->[8,4,5,6,7] , target is 6.... search is done on [4,5,6,7]
// 4 apply binary search on the half.
        while(low<=high){
            int mid=low + (high-low)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){
                
                if(nums[low]<=target and target<nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }else{
                if(nums[mid]<target and target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                //do
                
            }
            
        }
        return -1;
        
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){
                
                if(nums[low]<=target and target<nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }else{
                if(nums[mid]<target and target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                //do
                
            }
            
        }
        return -1;
        
    }
};