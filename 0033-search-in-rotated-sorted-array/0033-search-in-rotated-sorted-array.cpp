class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left=0;
        int right=arr.size()-1;
        int mid=left+(right-left)/2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[left] <= arr[mid]) {
                // left range is sorted
                if (arr[left] <= target && target < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            else {
                // right range is sorted
                if (arr[mid] < target && target <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
       
    }
};