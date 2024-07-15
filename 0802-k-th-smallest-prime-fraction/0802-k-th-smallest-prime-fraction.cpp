class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double ans=double(arr[i])/arr[j];
                pq.push({ans,{arr[i],arr[j]}});
            }
        }
        for(int i=1; i<k; i++)
        {
            pq.pop();
        }
        auto ans=pq.top();
        return {ans.second.first,ans.second.second};
    }
};