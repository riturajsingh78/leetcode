class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        // Check palindrome feasibility (guaranteed by problem, but safe to check)
        int oddCount = 0;
        for (int f : count) if (f % 2) oddCount++;
        if (oddCount > 1) return "";

        vector<int> halfCount(26, 0);
        char midLetter = 0;
        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2) midLetter = 'a' + i;
        }

        long long total = countArrangements(halfCount);
        if (k > total) return "";

        int halfLen = 0;
        for (int f : halfCount) halfLen += f;

        string left;
        left.reserve(halfLen);
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                if (arrangements >= k) {
                    left.push_back('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        string right(left.rbegin(), left.rend());
        string result = left;
        if (midLetter) result.push_back(midLetter);
        result += right;
        return result;
    }

private:
    static constexpr long long CAP = 1'000'000'000LL + 1; // cap large enough to exceed any valid k

    long long countArrangements(vector<int>& count) {
        long long total = 0;
        for (int f : count) total += f;
        long long res = 1;
        for (int f : count) {
            res = mulCapped(res, nCk(total, f));
            if (res >= CAP) return CAP;
            total -= f;
        }
        return res;
    }

    long long nCk(long long n, long long k) {
        if (k < 0 || k > n) return 0;
        k = min(k, n - k);
        long long res = 1;
        for (long long i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= CAP) return CAP;
        }
        return res;
    }

    long long mulCapped(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        if (a >= CAP || b >= CAP) return CAP;
        // avoid overflow
        __int128 r = (__int128)a * b;
        if (r >= CAP) return CAP;
        return (long long)r;
    }
};