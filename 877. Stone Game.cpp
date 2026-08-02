class Solution {
public:

    int t[501][501];
    int solve(int i, int j, vector<int>&arr){
        if(i>j){
            return 0;
        }
        if(i==j){
            return arr[i];
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        int take_i=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
        int take_j=arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr));

        return t[i][j]=max(take_i,take_j);
    }

    bool stoneGame(vector<int>& piles) {
         memset(t,-1,sizeof(t));

        int n=piles.size();
        int total_sum=0;

        for(int i=0;i<n;i++){
            total_sum+=piles[i];
        }
        int player_1=solve(0,n-1,piles);
        int player_2=total_sum-player_1;

        return player_1>=player_2;
    }
};