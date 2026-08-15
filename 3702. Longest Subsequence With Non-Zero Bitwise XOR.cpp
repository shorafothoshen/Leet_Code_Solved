class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        int xorx=0;
        bool hasNonZero=false;

        for(auto val:nums){
            xorx^=val;
            if(val!=0){
                hasNonZero=true;
            }
        }
        if(xorx!=0){
            return n;
        }
        if(hasNonZero){
            return n-1;
        }
        return 0;
    }
};