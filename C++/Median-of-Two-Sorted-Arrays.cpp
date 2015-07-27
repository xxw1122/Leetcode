class Solution {
public:
	double FindKth(vector<int> &nums1, vector<int> &nums2, int startA, int startB, int k) {
		if (startA >= nums1.size()) return nums2[startB + k - 1];
		if (startB >= nums2.size()) return nums1[startA + k - 1];
		if (k == 1) return min(nums1[startA], nums2[startB]);
		int valA = startA + k / 2 - 1 < nums1.size() ? nums1[startA + k / 2 - 1] : INT_MAX;
		int valB = startB + k / 2 - 1 < nums2.size() ? nums2[startB + k / 2 - 1] : INT_MAX;
		if (valA < valB) return FindKth(nums1, nums2, startA + k / 2, startB, k - k / 2);
		else return FindKth(nums1, nums2, startA, startB + k / 2, k - k / 2);
	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1) return FindKth(nums1, nums2, 0, 0, len / 2 + 1);
        else return (FindKth(nums1, nums2, 0, 0, len / 2) + FindKth(nums1, nums2, 0, 0, len / 2 + 1)) / 2.0;
    }
};