class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans=0;
        int low=0, high=letters.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target<letters[mid]){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return letters[ans];
    }
};