public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        int cur = 0;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] == target / 2 && target % 2 == 0) {
                if (cur < 2) res[cur ++] = i + 1;
            }
            hash.put(nums[i], i);
        }
        if (cur >= 2) return res;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] * 2 != target && hash.containsKey(target - nums[i])) {
                res[0] = hash.get(nums[i]) + 1;
                res[1] = hash.get(target - nums[i]) + 1;
            }
        }
        Arrays.sort(res);
        return res;
    }
}