using ll = long long;
constexpr int M = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        vector<ll> inc(r + 2, 0), dec(r + 2, 0);

        for (int i = l; i <= r; i++) inc[i] = dec[i] = 1;

        for (int len = 2; len <= n; len++) {
            vector<ll> ninc(r + 2, 0), ndec(r + 2, 0);
            ll pref = 0, suf = 0;
            for (int i = l; i <= r; i++) {
                ninc[i] = pref;
                pref = (pref + dec[i]) % M;
            }
            for (int i = r; i >= l; i--) {
                ndec[i] = suf;
                suf = (suf + inc[i]) % M;
            }
            inc = ninc, dec = ndec;
        }
        ll ans = 0;
        for (int i = l; i <= r; i++) ans = (ans + inc[i] + dec[i]) % M;
        return (int)ans;
    }
};