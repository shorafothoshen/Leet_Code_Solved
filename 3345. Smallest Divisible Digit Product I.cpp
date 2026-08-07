class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int ans=1;
            int tmp=n;
            while(tmp!=0){
                int digit=tmp%10;
                ans=ans*digit;
                tmp/=10;
            }
            if(ans%t==0){
                return n;
            }
            n++;
        }
    } 
};