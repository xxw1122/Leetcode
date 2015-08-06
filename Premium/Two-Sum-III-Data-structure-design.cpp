class TwoSum {
public:
	unordered_map<int, int> hash;
	vector<int> nums;
	void add(int number) {
	    nums.push_back(number);
	    if (hash.find(number) != hash.end()) {
	    	hash[number] ++;
	    } else {
	    	hash.insert(make_pair(number, 1));
	    }
	}

	bool find(int value) {
	    for (int i = 0; i < nums.size(); i ++) {
	    	if (nums[i] * 2 != value) {
	    		if (hash.find(value - nums[i]) != hash.end()) {
	    			return true;
	    		}
	    	} else {
	    		if (hash[nums[i]] >= 2) {
	    			return true;
	    		}
	    	}
	    }
	    return false;
	}
};