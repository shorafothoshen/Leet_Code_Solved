class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int mx = INT_MIN;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            mn = min(nums[i], mn);
        }

        int size = mx - mn;
        vector<int> hash(size + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i] - mn]++;
        }

        for (int i = mn; i <= mx; i++) {
            if (hash[i - mn] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};