Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Erase 还是能不用就不用吧
vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size()<2) return intervals;
    std::sort(intervals.begin(),intervals.end(),[] (Interval & a, Interval & b) { return a.start < b.start; });
    for(int i = 1; i <= intervals.size()-1; ++i){
        if (intervals[i-1].end >= intervals[i].start){
            if (intervals[i-1].end <= intervals[i].end) {
                intervals[i-1].end = intervals[i].end;
                intervals.erase(intervals.begin()+i);
                --i;
            }else{
                intervals.erase(intervals.begin()+i);
                --i;
            }
        }
    }
    vector<Interval> result;
    result.assign(intervals.begin(), intervals.end());
    return result;
}

A much faster way without the use of erase
vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size()<2) return intervals;
    vector<Interval> result;
    std::sort(intervals.begin(), intervals.end(), [] (Interval & a, Interval & b) {return a.start < b.start;});
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i){
        if (result.back().end < intervals[i].start) result.push_back(intervals[i]);
        else if (result.back().end < intervals[i].end) result[result.size()-1].end = intervals[i].end;
    }
    return result;
}
