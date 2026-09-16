class Solution {
public:
    static const int M = 1e9 + 7;

    int t[1001][1001];
    int prefix[1001][1001];

    int solve(int n, int k, int i) {

        if (k == 0)
            return 1;

        if (i >= n)
            return 0;

        if (t[k][i] != -1)
            return t[k][i];

        long long take = prefixSum(n, k - 1, i + 1);

        long long skip = solve(n, k, i + 1);

        return t[k][i] = (take + skip) % M;
    }

    int prefixSum(int n, int k, int i) {

        if (i >= n)
            return 0;

        if (prefix[k][i] != -1)
            return prefix[k][i];

        long long ans = solve(n, k, i);

        ans = (ans + prefixSum(n, k, i + 1)) % M;

        return prefix[k][i] = ans;
    }

    int numberOfSets(int n, int k) {

        memset(t, -1, sizeof(t));
        memset(prefix, -1, sizeof(prefix));

        return solve(n, k, 0);
    }
};