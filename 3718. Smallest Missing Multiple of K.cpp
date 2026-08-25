class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> multiple(102, false);

        for (int i = 0; i < n; i++) {
            if (nums[i] % k == 0) {
                multiple[nums[i] / k] = true;
            }
        }

        for (int i = 1; i < 102; i++) {
            if (multiple[i] == false) {
                return i * k;
            }
        }

        return k;
    }
};