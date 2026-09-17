class Solution {
public:
    bool isPalindrome(string s) {
        int f = 0;
        int e = s.size() - 1;
        while (f <= e) {
            if (isalnum(s[f]) == 0) {
                f++;
                continue;
            }

            if (isalnum(s[e]) == 0) {
                e--;
                continue;
            }

            if (tolower(s[f]) != tolower(s[e])) {
                return false;
            } else {
                f++;
                e--;
            }
        }

        return true;
    }
};