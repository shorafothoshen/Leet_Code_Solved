class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        int ans=0;

        for(auto ch:word){
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<>());

        for(int i=0;i<26;i++){
            ans+=mp[i]*((i/8)+1);
        }

        return ans;
    }
};