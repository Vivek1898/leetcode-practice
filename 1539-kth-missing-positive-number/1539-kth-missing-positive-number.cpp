class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0, end= arr.size();
        while(start<end){
            // Bs
            int mid = (start+end)/2;
            if (arr[mid] - (mid+1) < k){
                start=mid+1;
            }else{
                end = mid;
            }
        }
        return start+k;
    }
};