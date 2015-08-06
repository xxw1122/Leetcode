class TwoSum {
public:
	unordered_map<int, int> hash;
	vector<int> nums;
	void add(int number) {
		for (int i = 0; i < nums.size(); i ++) {
			int temp = nums[i] + number;
			hash[temp] ++;
		}
	    nums.push_back(number);
	}
	bool find(int value) {
	    return hash.find(value) != hash.end();
	}
};

