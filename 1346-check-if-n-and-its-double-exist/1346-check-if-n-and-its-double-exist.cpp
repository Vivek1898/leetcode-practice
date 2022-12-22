class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(count == 0){
                if(arr[i] == 0) {
                    count++;
                    continue;
                }
            }
            int lo = 0;
            int hi = arr.size() - 1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(arr[i] * 2 == arr[mid]) {
                    return true;
                }
                if(arr[mid] < arr[i] * 2) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};