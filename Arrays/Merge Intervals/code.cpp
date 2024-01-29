https://www.interviewbit.com/problems/merge-intervals/

/*
  sort the intervals.
Now taking one interval at a time hop on to the next interval to find if it merges. When we find that the next interval can no longer be merged, we stop and enter the value in the data structure and then update the value with the next interval and again start traversing and merging the intervals.
*/

bool cmp(Interval i1, Interval i2){
    return i2.start > i1.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
       intervals.push_back(newInterval);
       sort(intervals.begin(), intervals.end(), cmp);
       
       vector<Interval>ans;
       ans.push_back(intervals[0]);
       for(int i=1;i<intervals.size();i++){
           if(ans.back().end >= intervals[i].start){
               ans.back().end = max(ans.back().end, intervals[i].end);
           }
           else
               ans.push_back(intervals[i]);
       }
       return ans;
}
