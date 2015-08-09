/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size(), res = 1;
        if (len == 0) return 0;
        unordered_map<double, int> umap;
        for (int i = 0; i < len; i ++) {
            umap.clear();
            int samePointNum = 0,tmpres = 1;
            for (int j = i + 1; j < len; j ++) {
                double slope = std::numeric_limits<double>::infinity();//斜率初始化为无穷大，我们视横坐标相同的两点间的斜率为无穷大
                if (points[i].x != points[j].x) {
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);                    
                } else if (points[i].y == points[j].y) {
                    samePointNum ++;
                    continue;
                }
                int tmp;
                if (umap.find(slope) != umap.end()) {
                    tmp = ++ umap[slope];
                } else {
                    umap.insert(unordered_map<double, int>::value_type(slope, 2));
                    tmp = 2;
                }
                if(tmpres < tmp) tmpres = tmp;
            }
            if(res < tmpres + samePointNum) res = tmpres + samePointNum;
        }
        return res;
    }
};