class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sqSum=nums[0];

        for(int j=1;j<n;j++){
            if(nums[j]==nums[j-1]+1){
                sqSum+=nums[j];
            }else{
                break;
            }
        }

        unordered_set<int> present(nums.begin(), nums.end());

        while(present.count(sqSum)) {
            sqSum++;
        }

        return sqSum;
    }
};