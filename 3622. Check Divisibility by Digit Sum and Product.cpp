class Solution {
public:
    bool checkDivisibility(int n) {
        // 123456/10 = 12345
        // 123456%10 = 6

        int num = n;
        int sum = 0;
        int product = 1;

        while(num > 0){
            sum += num%10;
            product *= num%10;

            num = num/10;
        }

        if(n%(sum+product) == 0){
            return true;
        }
        return false;
    }
};