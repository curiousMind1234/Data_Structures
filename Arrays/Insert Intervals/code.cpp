vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
   int n = intervals.size(), i =0;
    vector<vector<int>> res;

    while(i<n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }
    while(i<n && newInterval[1] >= intervals[i][0]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    while(i<n){
        res.push_back(intervals[i]);
        i++;
    }
    return res; 
}
/*

Here 3 cases will arive:

Non Overlapping intervals before given newInterval -> push into the ans vector
Overlapping of intervals and newInterval update new interval
starting point of newInterval will be min of the interval starting point
or starting point of newInterval
Ending point will be the max of interval ending point or newInterval end point.
Non overlapping intervals after the newintervals have been merged -> push ito ans vector

Time complexity - O(N)
space complexity - O(1)

Also, please do not use sorting algo here because we have already provided with sorted list.

*/
