class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int subsets = 1 << n;
        vector<long long> subsetLCM(subsets, 1);
        for (int mask = 1; mask < subsets; mask++) {
            int i = __builtin_ctz(mask);     
            int rest = mask & (mask - 1);  
            if (rest == 0) {
                subsetLCM[mask] = coins[i];
            } else {
                long long l = lcm(subsetLCM[rest], (long long)coins[i]);
                subsetLCM[mask] = (l > (long long)2e15) ? (long long)2e15 + 1 : l;
            }
        }
        auto countLE = [&](long long v) -> long long {
            long long count = 0;
            for (int mask = 1; mask < subsets; mask++) {
                long long l = subsetLCM[mask];
                if (l > v) continue;
                int bits = __builtin_popcount(mask);
                long long c = v / l;
                count += (bits % 2 == 1) ? c : -c;
            }
            return count;
        };
        long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};