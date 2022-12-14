class Solution {
public:
    bool isPerfectSquare(int num) {
              int low=0;
        int high=num;
     
        while(low<=high){
       long long int mid=low+(high-low)/2;
        long long int sq=mid*mid;
        if(num==sq) return true;
        if(num>sq) low=mid+1;
        if(num<sq) high=mid-1;
         //    mid=low+(high-low)/2;
        }
        return false;
    }
};