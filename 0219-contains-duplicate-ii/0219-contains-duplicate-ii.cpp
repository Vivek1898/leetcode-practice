class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    int n=nums.size();
    unordered_map<int,int> mp;                       //key = element, value = index
    
    for(int i=0;i<n;i++){
        int curr=nums[i];
		
        if(mp.find(curr)!=mp.end()){                 //if curr_element is present in map
            if(abs(i-mp[curr]) <= k) return true;    //then check abs(i-mp[curr]) <= k, return true;
            mp[curr]=i;                              //else update the index of curr_element;
        }
        mp[curr]=i;                                  //else, push element and it's index into map
    }
    return false;
}
};