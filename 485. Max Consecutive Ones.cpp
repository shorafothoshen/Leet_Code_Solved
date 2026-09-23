class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>cnt_arr;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                cnt_arr.push_back(cnt);
                cnt=0;
            }
        }
        cnt_arr.push_back(cnt);
        int mx=INT_MIN;

        for(int i=0;i<cnt_arr.size();i++){
            mx=max(mx,cnt_arr[i]);
        }

        return mx;
    }
};