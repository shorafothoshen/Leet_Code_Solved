class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int mx=INT_MIN;
        int mx_num=0;
        for(auto x:mp){
           if(x.second > mx){
                mx = x.second;
                mx_num = x.first;
            }
        }

        return mx_num;
    }
};