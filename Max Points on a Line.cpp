#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


bool is_in_line(int X1,int Y1,int X2,int Y2,int X3,int Y3){
    return (X1-X2)*(Y3-Y2)-(X3-X2)*(Y1-Y2)==0;
}
    static bool cmp(Point s1,Point s2)
    {
        if(s1.x!=s2.x) return s1.x<s2.x;
        else return s1.y<s2.y;
    }
    int maxPoints(vector<Point> &points) {
        if(points.size()<=2) return points.size();
        vector<Point> points1;
        sort(points.begin(),points.end(),cmp);
        int arry[1000];
        memset(arry,0,sizeof(arry));
        points1.push_back(points[0]);
        arry[0]=1;
        for(int i=1;i<points.size();i++)
        {
            int k=points1.size();
            if(points1[k-1].x==points[i].x&&points1[k-1].y==points[i].y)
                {
                    arry[k-1]++;
                }
            else
            {
                points1.push_back(points[i]);
                arry[k]=1;
            }
        }
        if(points1.size()<=2) return points.size();
        //if(points.size()==2) return 2;
        int maxNum=2;
        int nIndex=points1.size();
    for(int i=0; i<nIndex; ++i){
        for(int j=i+1; j<nIndex; ++j){
            int cnt=arry[i]+arry[j];
            for(int k=j+1; k<nIndex; ++k){
                if(is_in_line(points1[i].x,points1[i].y,points1[j].x,points1[j].y,points1[k].x,points1[k].y))
                    cnt=cnt+arry[k];
            }
            if(cnt>maxNum) maxNum=cnt;
        }
    }
        return maxNum;
    }

int main()
    {
        int num;
        while(cin>>num)
            {
                vector<Point> vec;
                Point node;
                //vec.clear();
                for(int i=0;i<num;i++)
                    {
                        cin>>node.x>>node.y;
                        vec.push_back(node);
                    }
                int cnt=maxPoints(vec);
                cout<<cnt<<endl;
            }
        return 0;
    }