//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int x1=KnightPos[0] ;
	    int y1=KnightPos[1] ;
	    
	    int x2=TargetPos[0] ;
	    int y2=TargetPos[1] ;
	    
	    int count=0 ;
	    if(x1==x2 and y1==y2) return 0 ;
	    queue<pair<int,int>> q ;
	    q.push({x1,y1}) ;
	    vector<pair<int,int>> movements={
	        {2,1},
	        {2,-1},
	        {-2,1},
	        {-2,-1},
	        {1,2},
	        {1,-2},
	        {-1,2},
	        {-1,-2}
	    } ;
	    vector<vector<int>> vis(N,vector<int>(N,0)) ;
	    while(!q.empty()){
	        int n=q.size() ;
	        count++ ;
	        while(n--){
	            auto temp=q.front() ;
	            q.pop() ;
	            for(int i=0 ; i<movements.size() ; i++){
	                int X=movements[i].first+temp.first ;
	                int Y=movements[i].second+temp.second ;
	                if(X==x2 and Y==y2) return count ;
	                if(X>=1 and Y>=1 and X<=N and Y<=N and !vis[X-1][Y-1]){
	                    vis[X-1][Y-1]=1 ;
	                    q.push({X,Y}) ;
	                }
	            }
	        }
	    }
	    
	    return 0 ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends