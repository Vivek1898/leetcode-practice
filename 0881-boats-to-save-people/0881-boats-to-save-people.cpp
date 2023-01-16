class Solution2 {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        sort(p.begin(),p.end());
        int low=0;
        int high=p.size()-1;
        int count=0;
        while(low<=high){
            int sum=p[low]+p[high];
            
            if(sum<=limit){
                low++;
                high--;
                
            }else{
                high--;
            }
            count++;
            
        }
        return count;
    }
};

class Solution {
    public:
    
bool check(int mid,vector<int>people,int limit)
{
int i = 0, j = people.size() - 1,cnt = 0;

    while(i <= j)
    {  
        if(people[i] + people[j] <= limit)
        {
            ++i;
            --j;
        }
        else
        {
            --j;
        }
        
        ++cnt;  // number of boats
    }
    
    return cnt<=mid;
}
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int low=0;
    int ans=0;
    int high=people.size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(mid,people,limit)==true)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
   
}
};