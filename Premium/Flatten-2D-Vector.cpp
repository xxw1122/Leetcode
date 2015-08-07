class Vector2D {
public:
	vector<vector<int> > vec;
	int x, y;
	void find_next(int &x, int &y) {
		while (x < vec.size() && y >= vec[x].size()) {
        	y = 0;
        	x += 1;
        }
	}
    Vector2D(vector<vector<int> >& vec2d) {
        x = 0;
        y = 0;
        vec.assign(vec2d.begin(), vec2d.end());
        find_next(x, y);
    }

    int next() {
        int temp = vec[x][y];
        y ++;
        find_next(x, y);
        return temp;
    }

    bool hasNext() {
        if (x < vec.size() && y < vec[x].size()) return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */