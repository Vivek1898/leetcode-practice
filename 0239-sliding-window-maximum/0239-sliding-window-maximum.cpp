class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int window_size) {
       vector<int> result;
  
  if (v.size() > 0) {
    if ( window_size > v.size()) {
      return result;
    }

    deque<int> window;

    //find out max for first window
    for(int i = 0; i < window_size; ++i) {
      while(!window.empty() && v[i] >= v[window.back()]) {
        window.pop_back();
      }

      window.push_back(i);
    }
    result.push_back(v[window.front()]);
    for (int i = window_size; i < v.size(); ++i) {

      //remove all numbers that are smaller than current number
      //from the tail of list
      while(!window.empty() && v[i] >= v[window.back()]) {
        window.pop_back();
      }

      //remove first number if it doesn't fall in the window anymore
      if(!window.empty() && window.front() <= i - window_size ) {
        window.pop_front();
      }

      window.push_back(i);
      result.push_back(v[window.front()]);
    }
    return result;
  }
  else
    return result; 
    }
};