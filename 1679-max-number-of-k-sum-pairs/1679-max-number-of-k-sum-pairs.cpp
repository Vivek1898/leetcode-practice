class Solution {
public:
    int maxOperations(vector<int>& numbers, int target) {
    sort(numbers.begin(),numbers.end());
 vector<int>ans;
    int low=0, high = numbers.size()-1;
        int count =0;
    while(low<high){
        int sum=numbers[low] + numbers[high];
        if( sum == target){
         count++;
            low++;
            high--;
        }
        
        if(sum < target)
            low++;
        else if(sum > target)
            high--;
    }
    return count;
    }
};