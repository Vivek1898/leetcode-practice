class Solution {
public:
    int merge(vector<int> &nums,int l,int mid, int e)
    {
        int pair=0;
        int n = e-l+1;
        int i=l,j=mid+1;
        //To count reverse pairs
        while(i<=mid && j<=e)
        {
            if((long)nums[i] > (long)2*nums[j])
            {
               j++;
                pair += mid-i+1;
            }
            else
            {
                i++;
               // pair += mid-i+1;
            }
        }

        //sorting
        vector<int> temp(n); 
        i=l,j=mid+1;
        int k=0; 
        while(i<=mid && j<=e)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++] = nums[i++];
        }
        while(j<=e)
        {
            temp[k++] = nums[j++];
        }
        //Copying the values again in nums
        k=l;
        for(int z=0;z<n;z++)
        {
            nums[k++] = temp[z];
        }
        return pair;
    }
    int mergeSort(vector<int> &nums, int l,int e)
    {
        if(l==e)return 0;
        
        int mid = (l+e)/2;
        int left = mergeSort(nums,l,mid);
         int right = mergeSort(nums,mid+1,e);
         int cross= merge(nums,l,mid,e);

        return left+right+cross;
    }
    int reversePairs(vector<int>& nums) {
        int ans = mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};