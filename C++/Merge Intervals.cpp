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

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> vec;
    if(intervals.size()==0) return vec;
    sort(intervals.begin(),intervals.end(),cmp);
    Interval cur,cnt=intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(cnt.end>=intervals[i].start){
            cur.start=min(cnt.start,intervals[i].start);
            cur.end=max(cnt.end,intervals[i].end);
            cnt=cur;
        }
        else{
            vec.push_back(cnt);
            cnt=intervals[i];
        }
    }
    vec.push_back(cnt);
    return vec;
}