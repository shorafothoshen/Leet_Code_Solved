class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MIN;

        int mn1 = INT_MAX;
        int mn2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if (nums[i] > mx2) {
                mx3 = mx2;
                mx2 = nums[i];
            }
            else if (nums[i] > mx3) {
                mx3 = nums[i];
            }

            if (nums[i] < mn1) {
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if (nums[i] < mn2) {
                mn2 = nums[i];
            }
        }

        long long ans1 = 1LL * mx1 * mx2 * mx3;
        long long ans2 = 1LL * mx1 * mn1 * mn2;

        return max(ans1, ans2);
    }
};