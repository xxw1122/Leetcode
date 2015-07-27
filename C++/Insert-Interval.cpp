#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool cmp(Interval x,Interval y){
    if(x.start!=y.start) return x.start<y.start;
    else return x.end<y.end;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    sort(intervals.begin(),intervals.end(),cmp);
    vector<Interval> vec;
    int tag=0;
    for(int i=0;i<intervals.size();i++){
        if(tag==0){
            if(intervals[i].end<newInterval.start){
                vec.push_back(intervals[i]);
            }
            else if(intervals[i].start>newInterval.end){
                vec.push_back(newInterval);
                vec.push_back(intervals[i]);
                tag=1;
            }
            else{
                newInterval.start=min(intervals[i].start,newInterval.start);
                newInterval.end=max(intervals[i].end,newInterval.end);
            }
        }
        else{
            vec.push_back(intervals[i]);
        }
    }
    if(tag==0) vec.push_back(newInterval);
    return vec;
}