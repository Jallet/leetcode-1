/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int i = 0;
        for (i = 0; i < intervals.size(); i++)
        {        
            if (newInterval.start > intervals[i].end) 
                ret.push_back(intervals[i]); 
            else if (newInterval.end < intervals[i].start) 
            {
                ret.push_back(newInterval); 
                newInterval = intervals[i]; 
            }
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        ret.push_back(newInterval);
        return ret;
    }
};
