class Solution {
public:
      struct Points { 
	int start; 
	int end; 
	 
}; 

// Sorting Pointss based on finish time
static bool endSort(struct Points m1, Points m2) 
{ 
	return (m1.end < m2.end); 
} 
    
    int findMinArrowShots(vector<vector<int>>& intervals) {
          int n=intervals.size();
	struct Points meet[n];
	int c = 1;
	// Creating pairs of Points(start,end) and position
	for (int i = 0; i < n; i++) 
	{ 
		meet[i].start = intervals[i][0]; 
		meet[i].end = intervals[i][1]; 
		
	} 

	// Sorting of Pointss in ascending order according to their finish time 
	sort(meet, meet + n, endSort); 

	// Vector for storing selected Points. 
	//vector<int> m; 

	// First Points is always selected 
//	m.push_back(meet[0].pos); 
 
	int prev_end = meet[0].end; 

	// Checking if Points can take place or not 
	for (int i = 1; i < n; i++) { 
		if (meet[i].start > prev_end) 
		{ 
		//	m.push_back(meet[i].pos); 
			prev_end = meet[i].end; 
			c++;
		} 
	} 
	return c;
    }
};